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
const int maxn=500005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int a[maxn];
int num=0;

int gcd(int x,int y) {  
    ll z;  
    if (x<y) swap(x,y);  
    while (y) {  
        z=y;y=x%y;x=z;  
    }  
    return x;  
}  

struct Tree {
	int lc,rc,l,r,g;
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
		tree[now].g=gcd(tree[tree[now].lc].g,tree[tree[now].rc].g);
	} else tree[now].g=a[l];
}

void update (int now,int l,int r,int c) {
	if (tree[now].l>=l&&tree[now].r<=r) {
		tree[now].g=c;
	} else {
		if (l<=(tree[now].l+tree[now].r)/2) 
		    update(tree[now].lc,l,r,c);
		if (r>(tree[now].l+tree[now].r)/2)
		    update(tree[now].rc,l,r,c);
		tree[now].g=gcd(tree[tree[now].lc].g,tree[tree[now].rc].g);
	}
}

int findcnt (int now,int l,int r,int c) {
	if (tree[now].l==tree[now].r&&tree[now].g%c!=0) return 1;
	if (tree[now].l>=l&&tree[now].r<=r) {
		if (tree[now].g%c==0) return 0;
		int ans=0;
		ans+=findcnt(tree[now].lc,l,r,c);
		if (ans>1) return ans;
		ans+=findcnt(tree[now].rc,l,r,c);
		return ans;
	} else {
		int ans=0;
		if (l<=(tree[now].l+tree[now].r)/2) 
		    ans+=findcnt(tree[now].lc,l,r,c);
		if (ans>1) return ans;
		if (r>(tree[now].l+tree[now].r)/2)
		    ans+=findcnt(tree[now].rc,l,r,c);
		return ans;
	}
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].max << ' ' << tree[now].tag << endl;
}

int main() {
	int n,i,j,q,x,t,l,r;
	scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&q);
	num=1;
	build(1,1,n);
	for (i=1;i<=q;i++) {
		scanf("%d",&t);
		if (t==1) {
			scanf("%d%d%d",&l,&r,&x);
			int cnt=findcnt(1,l,r,x);
			if (cnt>1) printf("NO\n"); else printf("YES\n");
		} else {
			scanf("%d%d",&l,&x);
			update(1,l,l,x);
		}
	}
	return 0;
}
