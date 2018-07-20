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
int a[maxn];
vector<int> v; 
int num=1;

truct Tree {
	int lc,rc,l,r,max,min;
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
		tree[now].max=max(tree[tree[now].lc].max,tree[tree[now].rc].max);
		tree[now].min=min(tree[tree[now].lc].min,tree[tree[now].rc].min);
	} else tree[now].max=tree[now].min=a[l];
}

int findmax (int now,int l,int r) {
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].max << ' ' << tree[now].tag << endl;
	if (tree[now].l>=l&&tree[now].r<=r) {
		return tree[now].max;
	} else {
		int ans=-inf;
		if (l<=(tree[now].l+tree[now].r)/2) 
		    ans=max(ans,findmax(tree[now].lc,l,r));
		if (r>(tree[now].l+tree[now].r)/2)
		    ans=max(ans,findmax(tree[now].rc,l,r));
		return ans;
	}
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].max << ' ' << tree[now].tag << endl;
}

int findmin (int now,int l,int r) {
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].max << ' ' << tree[now].tag << endl;
	if (tree[now].l>=l&&tree[now].r<=r) {
		return tree[now].min;
	} else {
		int ans=-inf;
		if (l<=(tree[now].l+tree[now].r)/2) 
		    ans=min(ans,findmin(tree[now].lc,l,r));
		if (r>(tree[now].l+tree[now].r)/2)
		    ans=min(ans,findmin(tree[now].rc,l,r));
		return ans;
	}
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].max << ' ' << tree[now].tag << endl;
}

int main() {
	int n,i,j;
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	num=1;
	build(1,1,n);
	int ans=2*inf;
	for (i=1;i<=sqrt(n);i++) {
		if (n%i==0) {
			v.push_back(i);
			if (i*i!=n) v.push_back(n/i);
		}
	}
	for (int t=0;t<v.size();t++) {
		int size=v[t],mn,mx;
		mn=2*inf;mx=-2*inf;
		for (i=1;i<=n/size;i++) {
			if (i!=1) 
		}
	}
	return 0;
}
