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
const int maxn=1005,maxk=30005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int dfn[maxn],low[maxn],head[maxn];
bool visit[maxn],br[maxk],br1[maxk],use[maxk];
vector<int> path,oit,pa;
int num,ans;

struct Edge {
	int from,to,pre,dist;
};
Edge edge[maxk*2];

void addedge(int from,int to,int dist) {
	edge[num]=(Edge){from,to,head[from],dist};
	head[from]=num++;
	edge[num]=(Edge){to,from,head[to],dist};
	head[to]=num++;
}

bool dfs(int now,int t,int p) {
	if (now==t) return true;
	visit[now]=1;
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (p==i/2) continue;
		if (!visit[to]) {
			if (dfs(to,t,p)) {
				if (p==0) path.push_back(i/2); else pa.push_back(i/2);
				return true;
			}
		}
	}
	return false;
}

void tarjan(int now,int fa,int t,int p)
{
    dfn[now]=low[now]=++num;
    for(int i=head[now];i!=-1;i=edge[i].pre) {
        int to=edge[i].to;
        if (i/2==p||use[i/2]) continue;
        use[i/2]=1;
        if(!dfn[to])
        {
            tarjan(to,now,t,p);
            low[now]=min(low[now],low[to]);
            if(low[to]>dfn[now])
                if (t==0) br[i/2]=1; else br1[i/2]=1;
        }
        else if(dfn[to]<dfn[now])
        {
            low[now]=min(low[now],dfn[to]);
        }
    }
}

int main() {
	int n,m,i,j,x,y,d,s,t;
	scanf("%d%d%d%d",&n,&m,&s,&t);
	num=2;memset(head,-1,sizeof(head));
	for (i=1;i<=m;i++) {
		scanf("%d%d%d",&x,&y,&d);
		addedge(x,y,d);
	}
	ans=inf*2;
	mem0(visit);path.clear();
	if (!dfs(s,t,0)) {
		printf("0\n0\n");return 0;
	}
	mem0(br);mem0(dfn);mem0(low);mem0(use);num=0;
	for (i=1;i<=n;i++)
		if (!dfn[i]) tarjan(i,0,0,0);
	int size=path.size();
	for (i=0;i<size;i++) {
		int now=path[i];
		if (br[now]) {
			if (ans>edge[now*2].dist) {
				ans=edge[now*2].dist;
				oit.clear();oit.push_back(now);
			}
		} else {
			pa.clear();mem0(visit);
			if (dfs(s,t,now)) {
				mem0(br1);mem0(dfn);mem0(low);mem0(use);num=0;
				for (j=1;j<=n;j++)
					if (!dfn[j]) tarjan(j,0,1,now);
				int s2=pa.size();
				for (j=0;j<s2;j++)
					if (br1[pa[j]]) 
						if (ans>edge[now*2].dist+edge[pa[j]*2].dist) {
							ans=edge[now*2].dist+edge[pa[j]*2].dist;
							oit.clear();
							oit.push_back(now);oit.push_back(pa[j]);
						}
			}
		}
	}
	if (ans==2*inf) 
		printf("-1\n");
	else {
		printf("%d\n",ans);
		printf("%d\n",oit.size());
		for (j=0;j<oit.size();j++) printf("%d ",oit[j]);
	}
	return 0;
}
