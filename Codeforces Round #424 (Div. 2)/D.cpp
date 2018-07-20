#include <cstdio>
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <math.h>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn=3005,maxk=4000005;
const int inf=0x3f3f3f3f;
const ll llinf=1e16;
int current[maxn],dist[maxn],num,c[maxn],b[maxn],head[maxn];
int a[maxn][maxn];
int m,k;

struct Edge {
	int from,to,flow,pre;
}; 
Edge edge[maxk];

void addedge(int s,int t,int flow) {
	edge[num]=(Edge){s,t,flow,head[s]};
	head[s]=num;
	num++;
	edge[num]=(Edge){t,s,0,head[t]};
	head[t]=num;
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
		for (int i=head[now];i!=-1;i=edge[i].pre) {
			int k=i,to=edge[i].to;
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
	int f;
	for (int i=current[now];i!=-1;i=edge[i].pre) {
		int k=i,to=edge[i].to;
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
		memcpy(current,head,sizeof(current));
		while (f=dfs(0,inf,t)) sum+=f;
	}
	return sum;
}

void buildgraph(ll mid,int n) {
	int i,j;
	num=0;
	memset(head,-1,sizeof(head));
	for (i=1;i<=m;i++) addedge(0,i,1),addedge(i+m,n,1);
	for (i=m+1;i<=k;i++) addedge(i+m,n,1);
	for (i=1;i<=m;i++) {
	    for (j=1;j<=k;j++) 
		    if (a[i][j]<=mid) {
		    	addedge(i,j+m,1);
		    }
	}
}

ll solve(int n,int sum) {
	ll l=0,r=2e9,mid;
	int i;
	ll ans=-1;
	while (l<=r) {
		mid=(l+r)/2;
		buildgraph(mid,n);
		if (dinic(n)>=sum) {
			ans=mid;
			r=mid-1;
		} else l=mid+1;
	}
	return ans;
}

int main() {
	int p,i,j;
	scanf("%d%d%d",&m,&k,&p);
	for (i=1;i<=m;i++) scanf("%d",&b[i]);
	for (i=1;i<=k;i++) {
		scanf("%d",&c[i]);
		for (j=1;j<=m;j++) {
			if ((p>=c[i]&&c[i]>=b[j])||(p<=c[i]&&c[i]<=b[j]))
			    a[j][i]=abs(b[j]-p);
			else 
			    a[j][i]=abs(c[i]-p)+abs(b[j]-c[i]);
		}
	}
	int ans=solve(m+k+1,m);
	printf("%d\n",ans);
	return 0;
}
