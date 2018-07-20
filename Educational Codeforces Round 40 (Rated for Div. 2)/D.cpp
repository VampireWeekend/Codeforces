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
const int maxn=1005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int dist[maxn],head[maxn],dis[maxn];
bool inque[maxn],f[maxn][maxn];
int num=0;
vector<int> v[maxn];

struct Edge {
	int from,to,pre,dist;
};
Edge edge[maxn*2];

void addedge(int from,int to,int dist) {
	edge[num]=(Edge){from,to,head[from],dist};
	head[from]=num++;
	edge[num]=(Edge){to,from,head[to],dist};
	head[to]=num++;
}

void spfa(int s,int des){
	int i;
    memset(inque,0,sizeof(inque));
    memset(dist,0x3f,sizeof(dist));
	inque[s]=1;
	queue<int> q;
	q.push(s);
	dist[s]=0;
	while (!q.empty()) {
		int now=q.front();
		q.pop();
		inque[now]=0;
		for (i=head[now];i!=-1;i=edge[i].pre) {
			int to=edge[i].to;
			if (dist[edge[i].from]+edge[i].dist<dist[to]) {
				q.push(to);
				dist[to]=dist[edge[i].from]+edge[i].dist;
			}
		}
	}
}

void spf(int s,int des){
	int i;
    memset(inque,0,sizeof(inque));
    memset(dis,0x3f,sizeof(dis));
	inque[s]=1;
	queue<int> q;
	q.push(s);
	dis[s]=0;
	while (!q.empty()) {
		int now=q.front();
		q.pop();
		inque[now]=0;
		for (i=head[now];i!=-1;i=edge[i].pre) {
			int to=edge[i].to;
			if (dis[edge[i].from]+edge[i].dist<dis[to]) {
				q.push(to);
				dis[to]=dis[edge[i].from]+edge[i].dist;
			}
		}
	}
}

int main() {
	int n,m,i,j,x,y,s,t;
	num=0;
	memset(head,-1,sizeof(head));
	mem0(f);
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for (i=1;i<=m;i++) {
		scanf("%d%d",&x,&y);
		addedge(x,y,1);
		f[x][y]=f[y][x]=1;
	}
	spfa(s,t);
	spf(t,s);
	int ans=0;
	for (i=1;i<=n;i++) {
		for (j=i+1;j<=n;j++) {
			if (f[i][j]) continue;
			if (1+dist[i]+dis[j]>=dist[t]&&1+dist[j]+dis[i]>=dist[t]) ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
