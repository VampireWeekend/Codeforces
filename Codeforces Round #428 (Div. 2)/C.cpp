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
#include <iomanip>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double db;
const int maxn=100005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
int head[maxn];
int num;
bool visit[maxn];
db ans;

struct Edge {
	int from,to,pre;
};
Edge edge[maxn*2];

void addedge(int from,int to) {
	edge[num]=(Edge){from,to,head[from]};
	head[from]=num++;
	edge[num]=(Edge){to,from,head[to]};
	head[to]=num++;
}

void dfs(int now,db step,db p) {
	visit[now]=1;
	db m=0.0L;
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to]) 
			m+=1.0L;
	}
	if (!m) {
		ans+=step*p;return;
	}
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to]) 
			dfs(to,step+1.0L,p/m);
	}	
}

int main() {
	int n,i,x,y;
	num=0;mem0(visit);
	memset(head,-1,sizeof(head));
	scanf("%d",&n);
	for (i=1;i<n;i++) {
		scanf("%d%d",&x,&y);
		addedge(x,y);
	}
	dfs(1,0.0L,1.0L);
	cout << setiosflags(ios::fixed) << setprecision(10);
	cout << ans;
	return 0;
}
