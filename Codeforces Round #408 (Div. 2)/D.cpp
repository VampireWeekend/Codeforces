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
#include <bitset>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=300005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);
int head[maxn],a[maxn];
int num;
bool visit[maxn],mark[maxn];

struct node {
	int id,dist;
	node (int id,int dist): id(id),dist(dist) {}
};

struct Edge {
	int from,to,pre,id;
};
Edge edge[maxn*2];

void addedge(int from,int to,int id) {
	edge[num]=(Edge){from,to,head[from],id};
	head[from]=num++;
	edge[num]=(Edge){to,from,head[to],id};
	head[to]=num++;
}

int main() {
	num=0;mem0(visit);
	memset(head,-1,sizeof(head));
	queue<node> q;
	int n,k,d,x,y,i;
	scanf("%d%d%d",&n,&k,&d);
	for (i=1;i<=k;i++) {
		scanf("%d",&a[i]);
		q.push(node(a[i],0));
		visit[a[i]]=1;
	}
	for (i=1;i<n;i++) {
		scanf("%d%d",&x,&y);
		addedge(x,y,i);
	}
	mem0(mark);
	while (!q.empty()) {
		node now=q.front();
		q.pop();
		for (int i=head[now.id];i!=-1;i=edge[i].pre) {
			int to=edge[i].to;
			if (!visit[to]) {
				mark[edge[i].id]=visit[to]=1;
				if (now.dist<d) q.push(node(to,now.dist+1));
			}
		}
	}
	int ans=0;
	for (i=1;i<n;i++) {
		if (!mark[i]) ans++;
	}
	printf("%d\n",ans);
	for (i=1;i<n;i++) {
		if (!mark[i]) printf("%d ",i);
	}
	return 0;
}
