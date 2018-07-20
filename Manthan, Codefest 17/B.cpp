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
const int maxn=100005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
ll a[maxn],dp[maxn];
int num;

struct Tree {
	int lc,rc,l,r,max,tag;
};
Tree tree[4*maxn];

bool cmp(Tree a,Tree b) {
	if (a.max+a.tag>b.max+b.tag) return true; else return false;
}

void pushup(int now) {
	if (cmp(tree[tree[now].lc],tree[tree[now].rc])) 
		tree[now].max=tree[tree[now].lc].max+tree[tree[now].lc].tag;
	 else 
		tree[now].max=tree[tree[now].rc].max+tree[tree[now].rc].tag;
}

void pushdown(int now) {
	if (tree[now].tag==0) return;
	tree[tree[now].lc].tag+=tree[now].tag;
	tree[tree[now].rc].tag+=tree[now].tag;
	tree[now].max+=tree[now].tag;
	tree[now].tag=0;
}

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
		pushup(now);
	} else tree[now].max=a[l];
}

void update (int now,int l,int r,int c) {
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].max << ' ' << tree[now].tag << endl;
	if (tree[now].l>=l&&tree[now].r<=r) {
		tree[now].tag+=c;
	} else {
		pushdown(now);
		if (l<=(tree[now].l+tree[now].r)/2) 
		    update(tree[now].lc,l,r,c);
		if (r>(tree[now].l+tree[now].r)/2)
		    update(tree[now].rc,l,r,c);
		pushup(now);
	}
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].max << ' ' << tree[now].tag << endl;
}

int findmax (int now,int l,int r) {
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].max << ' ' << tree[now].tag << endl;
	if (tree[now].l>=l&&tree[now].r<=r) {
		return tree[now].max+tree[now].tag;
	} else {
		pushdown(now);
		int ans=-inf;
		if (l<=(tree[now].l+tree[now].r)/2) 
		    ans=max(ans,findmax(tree[now].lc,l,r));
		if (r>(tree[now].l+tree[now].r)/2)
		    ans=max(ans,findmax(tree[now].rc,l,r));
		return ans;
	}
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].max << ' ' << tree[now].tag << endl;
}

int main() {
	ll n,p,q,r,i,j,x,y,c,ans;
	scanf("%lld%lld%lld%lld",&n,&p,&q,&r);
	x=llinf;y=-llinf;
	for (i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
		dp[i]=a[i]*p;
	}
	x=llinf;y=-llinf;
	for (i=1;i<=n;i++) {
		y=max(y,dp[i]);
		dp[i]=y+q*a[i];
	//	cout << dp[i] << endl;
	}
	ans=-llinf;
	x=llinf;y=-llinf;
	for (i=1;i<=n;i++) {
		y=max(y,dp[i]);
		dp[i]=y+r*a[i];
		ans=max(ans,dp[i]);
	//	cout << dp[i] << endl;
	}
	printf("%lld\n",ans);
	return 0;
}
