//最大流dinic算法 
#include <cstdio>
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <cmath>
using namespace std;
const int maxn=205,maxk=3000;
const int inf=0x3f3f3f3f;
int d[maxn],dist[maxn],current[maxn];
int t,i,j,m,s,q,x,y,n,num,sum;
vector<int> v[maxn];

struct Edge{
	int from,to,flow;
};
Edge edge[maxk*4];

void addedge(int s,int t,int flow) {
	edge[num].from=s;
	edge[num].to=t;
	edge[num].flow=flow;
	v[s].push_back(num);
	num++;
	edge[num].from=t;
	edge[num].to=s;
	edge[num].flow=0;
	v[t].push_back(num);
	num++;
}

int bfs(int n) {
	queue<int> q;
	memset(dist,-1,sizeof(dist));
	dist[0]=0;
	q.push(0);
	while (!q.empty()) {
		int now=q.front();
		q.pop();
		int size=v[now].size();
		for (int i=0;i<size;i++) {
			int k=v[now][i],to=edge[v[now][i]].to;
			if (dist[to]==-1&&edge[k].flow>0) {
				dist[to]=dist[now]+1;
				q.push(to);
			}
		}
	}
	if (dist[n]==-1) return 0; else return dist[n];
}

int dfs(int now,int flow,int t) {
	if (now==t) return flow;
	int size=v[now].size(),f;
	for (int i=current[now];i<size;i++) {
		int k=v[now][i],to=edge[v[now][i]].to;
		current[now]=i;
		if (edge[k].flow>0&&dist[to]==dist[now]+1&&(f=dfs(to,min(flow,edge[k].flow),t))) {
			edge[k].flow-=f;
			edge[k^1].flow+=f;
			return f;
		}
	}
	return 0;
}

int dinic(int t) {
	int f,sum=0;
	while (bfs(t)) {
		memset(current,0,sizeof(current));
		while (f=dfs(0,inf,t)) sum+=f;
	}
	return sum;
}

int main() {
	cin >> t;
	for (q=1;q<=t;q++) {
		memset(d,0,sizeof(d));
		num=0;
		scanf("%d%d",&n,&s);
		for (i=1;i<=s;i++) {
			scanf("%d%d%d",&x,&y,&m);
			if (x!=y)  {
				if (!m) 
				    addedge(x,y,1);
				d[x]++;d[y]--;
			}
		}
		int flag=0;
		sum=0;
		for (i=1;i<=n;i++) {
			if (d[i]%2) {
				cout << "impossible" << endl;
				flag=1;
				break;
			} else if (d[i]) {
				if (d[i]>0) addedge(0,i,d[i]/2); else addedge(i,n+1,-d[i]/2);
				sum+=abs(d[i]/2);
			}
		}
		if (!flag) {
			int f=dinic(n+1);
	//		cout << f << endl;
			if (f==sum/2) cout << "possible" << endl; else cout << "impossible" << endl;
		}
		for (i=0;i<=n+1;i++) v[i].clear();
	}
	return 0;
}
