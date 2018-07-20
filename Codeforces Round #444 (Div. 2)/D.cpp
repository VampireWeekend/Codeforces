#include <cstdio>
#include <iostream>
#include <string.h>
#include <string> 
#include <map>
#include <queue>
#include <deque>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>
#include <iomanip>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=300005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int t[maxn],q[maxn],x[maxn];

struct Tree {
	int lc,rc,l,r;
	ll sum,mlsum;
};

class SegmentTree {
public:
Tree tree[4*maxn];
int num;

void init(){
	num=1;
}

void build(int now,int l,int r) {
	tree[now].l=l;
	tree[now].r=r;
	if (l!=r) {
		num++;
		tree[now].lc=num;
		build(num,l,(l+r)/2);
		num++;
		tree[now].rc=num;
		build(num,(l+r)/2+1,r);
		tree[now].sum=tree[tree[now].lc].sum+tree[tree[now].rc].sum;
		tree[now].mlsum=min(tree[tree[now].lc].mlsum,
			tree[tree[now].lc].sum+tree[tree[now].rc].mlsum);
	} else {
		tree[now].sum=tree[now].mlsum=x[l];
	}
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << endl;
}

Tree findsum(int now,int l,int r) {
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].tag << endl;
	if (tree[now].l>=l&&tree[now].r<=r) {
		return tree[now];
	} else {
		Tree f,tem;
		if (l<=(tree[now].l+tree[now].r)/2) {
			f=findsum(tree[now].lc,l,r);
			if (r>(tree[now].l+tree[now].r)/2) {
				tem=findsum(tree[now].rc,l,r);
				f.mlsum=min(f.mlsum,f.sum+tem.mlsum);
				f.sum+=tem.sum;
			}
		} else
		if (r>(tree[now].l+tree[now].r)/2)
		    f=findsum(tree[now].rc,l,r);
		return f;
	}
}
private:
};
SegmentTree s1,s2;

int main() {
	int i,j,n,l,ans=-1;
	ll a,b,c,d,s,sum=0;
	s1.init();s2.init();
	scanf("%d%I64d%I64d%I64d%I64d%I64d%d",&n,&a,&b,&c,&d,&s,&l);
	sum=s;
	for (i=1;i<=n;i++) {
		scanf("%d%d",&t[i],&q[i]);
		if (q[i]==1) x[i]=a; else x[i]=-b;
		if (sum>=0) sum+=x[i];
	}
	s1.build(1,1,n);
	for (i=1;i<=n;i++) {
		if (q[i]==1) x[i]=c; else x[i]=-d;
	}
	s2.build(1,1,n);
	int hd,tl,tm=0,head=0;
	hd=1;tl=0;
	if (t[1]>=l&&sum>=0) 
		ans=0;
	t[n+1]=inf;
	for (i=1;i<=2*n;i++) {
		if (hd+1==tl||t[tl+1]<l) tl++; else 
		if (tl==n) hd++; else {
			if (t[tl+1]-l+1>t[hd+1]) hd++; else 
			if (t[tl+1]-l+1<t[hd+1]) tl++; else {
				hd++;tl++;i++;
			}
		}
		if (t[tl+1]<l) continue;
		head=min(t[tl]-l+1,t[hd]);
		Tree tmp;
		if (hd!=1) tmp=s1.findsum(1,1,hd-1); else tmp.sum=0;
		if (tmp.mlsum+s>=0||hd==1) {
			ll p=tmp.sum+s;
			tmp=s2.findsum(1,hd,tl);
			if (p+tmp.mlsum>=0) 
				ans=max(0,head);
		}
		if (ans!=-1) break;
	}
	if (sum>=0) 
		if (ans==-1) ans=t[n]+1;
	printf("%d\n",ans);
	return 0;
}
