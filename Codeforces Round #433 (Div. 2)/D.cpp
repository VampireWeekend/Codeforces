#include <cstdio>
#include <iostream>
#include <string.h>
#include <string> 
#include <map>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
#define N 1000000
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=1000005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
ll rc[maxn];
int to[100005];
int num;

struct flight {
	int d,t,c;
};
flight a[maxn],b[maxn];

bool cmp(flight a,flight b) {
	return a.d<b.d;
}

bool cmp2(flight a,flight b) {
	return a.d>b.d;
}

struct Tree {
	int lc,rc,l,r;
	ll min;
};
Tree tree[3*maxn];

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
		tree[now].min=min(tree[tree[now].lc].min,tree[tree[now].rc].min);
	} else tree[now].min=rc[l];
}

ll findmin (int now,int l,int r) {
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].max << ' ' << tree[now].tag << endl;
	if (tree[now].l>=l&&tree[now].r<=r) {
		return tree[now].min;
	} else {
		ll ans=llinf;
		if (l<=(tree[now].l+tree[now].r)/2) 
		    ans=min(ans,findmin(tree[now].lc,l,r));
		if (r>(tree[now].l+tree[now].r)/2)
		    ans=min(ans,findmin(tree[now].rc,l,r));
		return ans;
	}
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].max << ' ' << tree[now].tag << endl;
}

int main() {
	int n,m,k,i,j,x,y,z,w,m1,m2;
	m1=m2=0;
	scanf("%d%d%d",&n,&m,&k);
	for (i=1;i<=m;i++) {
		scanf("%d%d%d%d",&w,&x,&y,&z);
		if (y==0) {
			a[++m1].d=w;a[m1].t=x;a[m1].c=z;
		} else {
			b[++m2].d=w;b[m2].t=y;b[m2].c=z;
		}
	}
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp2);
	int cnt,last=-1;
	cnt=0;j=1;
	meminf(to);
	rc[N+1]=0;
	for (i=N;i>=1;i--) {
		rc[i]=rc[i+1];
		for (;b[j].d>=i&&j<=m2;j++) {
			if (to[b[j].t]==inf) {
				cnt++;
				to[b[j].t]=b[j].c;
				rc[i]+=(ll)b[j].c;
			} else {
				if (to[b[j].t]>b[j].c) {
					rc[i]-=(ll)(to[b[j].t]-b[j].c);
					to[b[j].t]=b[j].c;
				}
			}
		}
		if (cnt==n&&last==-1) last=i;
	}
	num=1;
	if (last==-1) {
		cout << -1;
		return 0;
	}
	build(1,1,last);
	meminf(to);
	ll ans=llinf,p=0;
	j=1;cnt=0;
	for (i=1;i+k<last;i++) {
		for (;a[j].d<=i&&j<=m1;j++) {
			if (to[a[j].t]==inf) {
				cnt++;
				to[a[j].t]=a[j].c;
				p+=(ll)a[j].c;
			} else {
				if (to[a[j].t]>a[j].c) {
					p-=(ll)(to[a[j].t]-a[j].c);
					to[a[j].t]=a[j].c;
				}
			}
		}
		if (cnt==n) 
			ans=min(ans,p+findmin(1,i+k+1,last));
	}
	if (ans==llinf) ans=-1;
	printf("%I64d",ans);
	return 0;
}
