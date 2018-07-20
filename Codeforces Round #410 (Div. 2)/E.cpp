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
const int maxn=500005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int a[maxn],b[maxn],ans[maxn];
bool visit[maxn];
int num,p,n;

struct Tree {
	int lc,rc,l,r,max,id;
};
Tree tree[4*maxn];

bool cmp(Tree a,Tree b) {
	if (a.max>b.max) return true; else return false;
}

void pushup(int now) {
	if (cmp(tree[tree[now].lc],tree[tree[now].rc])) {
		tree[now].max=tree[tree[now].lc].max;
		tree[now].id=tree[tree[now].lc].id;
	} else {
	 	tree[now].max=tree[tree[now].rc].max;
	 	tree[now].id=tree[tree[now].rc].id;
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
	} else tree[now].max=b[l],tree[now].id=l;
}

void update (int now,int pos) {
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].max << ' ' << tree[now].id << endl;
	if (tree[now].l==tree[now].r&&tree[now].l==pos) {
		tree[now].max=0;
	} else {
		if (pos<=(tree[now].l+tree[now].r)/2) 
		    update(tree[now].lc,pos);
		if (pos>(tree[now].l+tree[now].r)/2)
		    update(tree[now].rc,pos);
		pushup(now);
	}
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].max << ' ' << tree[now].id << endl;
}

Tree findmax(int now,int l,int r) {
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' '  << tree[now].max << ' ' << tree[now].id << endl;
	if (tree[now].l>=l&&tree[now].r<=r) {
		return tree[now];
	} else {
		Tree ans,f;
		ans.max=f.max=-1;
		if (l<=(tree[now].l+tree[now].r)/2) 
			ans=findmax(tree[now].lc,l,r);
		if (r>(tree[now].l+tree[now].r)/2) 
			f=findmax(tree[now].rc,l,r);
		if (cmp(f,ans)) ans=f;
//		cout << ans.max << ' ' << ans.id << endl;
		return ans;
	}
}

void dfs(int now) {
	visit[now]=1;
	update(0,now);
	if (b[now]!=n+1&&!visit[b[now]]) dfs(b[now]);
	if (a[now]<=1) {
		ans[now]=p++;
		return;
	}
	Tree to=findmax(0,1,a[now]-1);
//	cout << to.max << ' ' << to.id << endl;
	while (to.max>now) {
		if (!visit[to.id]) dfs(to.id);
		to=findmax(0,1,a[now]-1);
//		cout << to.max << ' ' << to.id << endl;
	}
	ans[now]=p++;
}

void trosort(int n) {
	mem0(visit);
	for (int i=1;i<=n;i++) 
		if (!visit[i]) dfs(i);
}

int main() {
	int i;
	scanf("%d",&n);
	p=1;
	for (i=1;i<=n;i++) b[i]=n+1;
	for (i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		if (a[i]==-1) a[i]=n+1; else b[a[i]]=i;
	}
	num=0;
	build(0,1,n);
	trosort(n);
	for (i=1;i<=n;i++) 
		printf("%d ",ans[i]);
	return 0;
}

