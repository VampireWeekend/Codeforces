#include <cstdio>
#include <iostream>
#include <string.h>
#include <algorithm>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=500005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
int head[maxn],size[maxn],son[maxn],ans[maxn];
int con[maxn],dep[maxn];
int mxd[5000005];
bool visit[maxn],big[maxn];
int num=0;

struct Edge {
	int from,to,pre,dist;
};
Edge edge[maxn*2];

void addedge(int from, int to,int dist) {
	edge[num]=(Edge){from,to,head[from],dist};
	head[from]=num++;
	edge[num]=(Edge){to,from,head[to],dist};
	head[to]=num++;
}

int dfs2(int now,int r,int step) {  
    visit[now]=1;son[now]=-1;size[now]=1;  
    con[now]=r;dep[now]=step;
    for (int i=head[now];i!=-1;i=edge[i].pre) {  
        int to=edge[i].to;  
        if (!visit[to]) {  
            size[now]+=dfs2(to,r^(1<<edge[i].dist),step+1);  
            if (son[now]==-1||size[to]>size[son[now]]) son[now]=to;  
        }  
    }
    if (son[now]!=-1) big[son[now]]=1;
    return size[now];
}  

int findmax(int now,int fa) {
	int ans=mxd[con[now]];
	for (int i=0;i<22;i++) ans=max(ans,mxd[con[now]^(1<<i)]);
	if (ans>0) ans+=dep[now];
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (to!=fa&&!big[to]) ans=max(ans,findmax(to,now));
	}
	return ans;
}

void add(int now,int fa) {
	mxd[con[now]]=max(mxd[con[now]],dep[now]);
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (to!=fa&&!big[to]) add(to,now);
	}
}

void eliminate(int now,int fa) {
	mxd[con[now]]=-inf;
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (to!=fa&&!big[to]) eliminate(to,now);
	}
}

void dfs(int now,int fa,bool rem) {
	int mx=0;
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (to!=fa&&!big[to]) dfs(to,now,0),mx=max(mx,ans[to]);
	}
	if (son[now]!=-1) dfs(son[now],now,1),mx=max(mx,ans[son[now]]);
	ans[now]=mx;
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (to!=fa&&!big[to]) {
			ans[now]=max(ans[now],findmax(to,now)-2*dep[now]);
			add(to,now);
		}
	}
	for (int i=0;i<22;i++) 
		ans[now]=max(ans[now],mxd[con[now]^(1<<i)]-dep[now]);
	ans[now]=max(ans[now],mxd[con[now]]-dep[now]);
	mxd[con[now]]=max(mxd[con[now]],dep[now]);
	if (son[now]!=-1) big[son[now]]=0;
	if (!rem) eliminate(now,fa);
}

int main() {
	memset(head,-1,sizeof(head));
	int n,i,j,x;
	char c;
	scanf("%d",&n);
	for (i=2;i<=n;i++) {
		scanf("%d %c",&x,&c);
		addedge(i,x,c-'a');
	}
	mem0(big);mem0(visit);
	dfs2(1,0,0);
	mem0(ans);
	dfs(1,0,0);
	for (i=1;i<=n;i++) printf("%d ",ans[i]); 
	return 0;
}
