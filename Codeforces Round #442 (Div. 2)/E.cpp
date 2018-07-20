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
const int maxn=200005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int head[maxn],in[maxn],out[maxn],a[maxn],s[maxn];
bool visit[maxn];
int num,dfn;

struct Edge {
	int from, to, pre;
};
Edge edge[maxn * 2];

void addedge(int from, int to) {
	edge[num] = (Edge){from, to, head[from]};
	head[from] = num++;
}

struct Tree {
	int lc,rc,l,r,sum,tag;
};
Tree tree[4*maxn];

void build(int now,int l,int r) {
	tree[now].l=l;
	tree[now].r=r;
	tree[now].sum=tree[now].tag=0;
	if (l!=r) {
		num++;
		tree[now].lc=num;
		build(num,l,(l+r)/2);
		num++;
		tree[now].rc=num;
		build(num,(l+r)/2+1,r);
		tree[now].sum=tree[tree[now].lc].sum+tree[tree[now].rc].sum;
	} else tree[now].sum=s[tree[now].l];
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << endl;
}

void pushdown(int now) {
	if (tree[now].tag==0) return;
	int l=tree[now].lc,r=tree[now].rc;
	tree[l].tag^=tree[now].tag;
	tree[r].tag^=tree[now].tag;
	tree[l].sum=tree[l].r-tree[l].l+1-tree[l].sum;
	tree[r].sum=tree[r].r-tree[r].l+1-tree[r].sum;
	tree[now].tag=0;
}

void update (int now,int l,int r) {
	if (tree[now].l>=l&&tree[now].r<=r) {
		tree[now].tag^=1;
		tree[now].sum=tree[now].r-tree[now].l+1-tree[now].sum;
	} else {
		pushdown(now);
		if (l<=(tree[now].l+tree[now].r)/2) 
		    update(tree[now].lc,l,r);
		if (r>(tree[now].l+tree[now].r)/2)
		    update(tree[now].rc,l,r);
		tree[now].sum=tree[tree[now].lc].sum+tree[tree[now].rc].sum;
	}
}

int findsum(int now,int l,int r) {
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].tag << endl;
	if (tree[now].l>=l&&tree[now].r<=r) {
		return tree[now].sum;
	} else {
		pushdown(now);
		int f=0;
		if (l<=(tree[now].l+tree[now].r)/2) 
		    f=findsum(tree[now].lc,l,r);
		if (r>(tree[now].l+tree[now].r)/2)
		    f+=findsum(tree[now].rc,l,r);
		return f;
	}
}

void dfs(int now) {
    s[++dfn]=a[now];
    in[now]=dfn;
    for (int i=head[now];i!=-1;i=edge[i].pre) {  
        int to=edge[i].to;  
        if (!visit[to]) {  
            dfs(to);
        }  
    }  
    out[now]=dfn;
}

int main() {
	int n,i,x,j,m;
	char t[15];
	num=dfn=0;memset(head,-1,sizeof(head));
	scanf("%d",&n);
	for (i=2;i<=n;i++) {
		scanf("%d",&x);addedge(x,i);
	}
	for (i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	dfs(1);
	num=1;build(1,1,n);
	scanf("%d",&m);
	for (i=1;i<=m;i++) {
		scanf("%s",t);
		if (t[0]=='g') {
			scanf("%d",&x);
			int ans=findsum(1,in[x],out[x]);
			printf("%d\n",ans);
		} else {
			scanf("%d",&x);
			update(1,in[x],out[x]);
		}
	}
	return 0;
}
