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
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=300005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
ll a[maxn],ans[maxn];
int num;

struct Tree {
	int lc,rc,l,r,max;
	ll num;
};
Tree tree[4*maxn];

void pushup(int now) {
	if (tree[tree[now].lc].max>tree[tree[now].rc].max) {
		tree[now].max=tree[tree[now].lc].max;
		tree[now].num=tree[tree[now].lc].num;
	}
	else {
		tree[now].max=tree[tree[now].rc].max;
		tree[now].num=tree[tree[now].rc].num;
	}
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
		pushup(now);
	} else tree[now].max=0,tree[now].num=l;
}

void update (int now,int l,int r,int c) {
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].max << ' ' << tree[now].num << endl;
	if (tree[now].l>=l&&tree[now].r<=r) {
		tree[now].max=c;
	} else {
		if (l<=(tree[now].l+tree[now].r)/2) 
		    update(tree[now].lc,l,r,c);
		if (r>(tree[now].l+tree[now].r)/2)
		    update(tree[now].rc,l,r,c);
		pushup(now);
	}
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].max << ' ' << tree[now].num << endl;
}

int main() {
	int n,k,j;
	ll i;
	scanf("%d%d",&n,&k);
	for (i=1;i<=n;i++) {
		scanf("%I64d",&a[i]);
	}
	ll tot=0;
	num=1;
	build(1,1,n);
	for (i=1;i<=k;i++) {
		update(1,i,i,a[i]);
	}
	for (i=k+1;i<=k+n;i++) {
		if (i<=n) update(1,i,i,a[i]);
		tot+=(i-tree[1].num)*a[tree[1].num];
		ans[tree[1].num]=i;
		update(1,tree[1].num,tree[1].num,0);
	}
	printf("%I64d\n",tot);
	for (i=1;i<=n;i++) {
		printf("%d ",ans[i]);
	}
	return 0;
}

