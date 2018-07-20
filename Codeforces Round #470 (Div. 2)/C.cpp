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
const int maxn=100005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
ll v[maxn],t[maxn],sum[maxn],ans[maxn];
int num=0;

struct Tree {
	int lc,rc,l,r;
	ll sum,tag;
};
Tree tree[4*maxn];

void build(int now,int l,int r) {
	tree[now].l=l;
	tree[now].r=r;
	tree[now].tag=0;
	if (l!=r) {
		num++;
		tree[now].lc=num;
		build(num,l,(l+r)/2);
		num++;
		tree[now].rc=num;
		build(num,(l+r)/2+1,r);
		tree[now].sum=tree[tree[now].lc].sum+tree[tree[now].rc].sum;
	} else tree[now].sum=0;
}

void pushdown(int now) {
	if (tree[now].tag==0) return;
	int l=tree[now].lc,r=tree[now].rc;
	tree[l].tag+=tree[now].tag;
	tree[r].tag+=tree[now].tag;
	tree[l].sum+=tree[now].tag*(tree[l].r-tree[l].l+1);
	tree[r].sum+=tree[now].tag*(tree[r].r-tree[r].l+1);
	tree[now].tag=0;
}

void update (int now,int l,int r,ll c) {
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].sum << ' ' << tree[now].tag << endl;
	if (tree[now].l>=l&&tree[now].r<=r) {
		tree[now].sum+=c*(tree[now].r-tree[now].l+1);
		tree[now].tag+=c; 
	} else {
		pushdown(now);
		if (l<=(tree[now].l+tree[now].r)/2) 
		    update(tree[now].lc,l,r,c);
		if (r>(tree[now].l+tree[now].r)/2)
		    update(tree[now].rc,l,r,c);
		tree[now].sum=tree[tree[now].lc].sum+tree[tree[now].rc].sum;
	}
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].sum << ' ' << tree[now].tag << endl;
}

ll findsum(int now,int l,int r) {
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].sum << ' ' << tree[now].tag << endl;
	pushdown(now);
	if (tree[now].l>=l&&tree[now].r<=r) {
		return tree[now].sum;
	} else {
		ll f=0;
		if (l<=(tree[now].l+tree[now].r)/2) 
		    f=findsum(tree[now].lc,l,r);
		if (r>(tree[now].l+tree[now].r)/2)
		    f+=findsum(tree[now].rc,l,r);
		return f;
	}
}

int main() {
	int n,m,i,j;
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		scanf("%I64d",&v[i]);
	}
	sum[0]=0;
	for (i=1;i<=n;i++) {
		scanf("%I64d",&t[i]);
		sum[i]=sum[i-1]+t[i];
		ans[i]=0;
	}
	num=1;
	build(1,1,n);
	for (i=1;i<=n;i++) {
		int pos=upper_bound(sum+1,sum+n+1,v[i]+sum[i-1])-sum;
		if (pos>i) update(1,i,pos-1,1);
		ans[pos]+=v[i]-(sum[pos-1]-sum[i-1]);
	}
	for (i=1;i<=n;i++) {
		ans[i]+=findsum(1,i,i)*t[i];
		printf("%I64d ",ans[i]);
	}
	return 0;
}
