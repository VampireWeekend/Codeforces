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
#include <assert.h>
#define pb push_back 
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef pair<int,int> pp;
const int maxn=200005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
int first[maxn],last[maxn],a[maxn];
int num=0;

struct Tree {
	int lc,rc,l,r,min;
};
Tree tree[4*maxn];

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
	} else tree[now].min=a[l];
}

int findmin(int now,int l,int r) {
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].min << endl;
	if (tree[now].l>=l&&tree[now].r<=r) {
		return tree[now].min;
	} else {
		int ans=inf;
		if (l<=(tree[now].l+tree[now].r)/2) 
		    ans=min(ans,findmin(tree[now].lc,l,r));
		if (r>(tree[now].l+tree[now].r)/2)
		    ans=min(ans,findmin(tree[now].rc,l,r));
		return ans;
	}
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].max << ' ' << tree[now].tag << endl;
}

int main() {
	int n,m,cnt=0;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		if (!first[a[i]]) first[a[i]]=i;
		last[a[i]]=i;
		if (a[i]==0) a[i]=inf,cnt++;
	}
	if (cnt==n) {
		printf("YES\n");
		for (int i=1;i<=n;i++) {
			printf("%d ",m);
		}
		return 0;
	}
	if (first[m]==0) {
	    if (cnt==0) {
	        printf("NO");return 0;
	    } else {
	        first[m]=last[m]=first[0];a[first[0]]=m;
	    }
	}
	num=1;
	build(1,1,n);
	for (int i=1;i<=m;i++) {
		if (first[i]+1>last[i]-1) continue;
		int now=findmin(1,first[i]+1,last[i]-1);
		if (now<i) {
			printf("NO");return 0;
		}
	}
	printf("YES\n");
	int last=0;
	for (int i=1;i<=n;i++) {
		if (a[i]==inf) continue;
		for (int j=last+1;j<=i;j++)
			printf("%d ",a[i]);
		last=i;
	}
	if (last!=n) {
	    for (int j=last+1;j<=n;j++)
			printf("%d ",a[last]);
	}
	return 0;
}