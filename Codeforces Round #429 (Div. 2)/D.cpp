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
const int maxn=300005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);  
int head[maxn],d[maxn];
bool visit[maxn],f[maxn];
int num,sum;

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

void dfs(int now,int pre,int fa) {
	visit[now]=1;
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to]) dfs(to,i,now);
	}
	if (now==1||d[now]==0) return;
	sum++;
	f[pre/2+1]=1;
	d[fa]=(d[fa]+1)%2;
}

int main() {
	int n,i,j,m,x,y,cnt=0;
	sum=0;
	scanf("%d%d",&n,&m);
	num=0;
	memset(head,-1,sizeof(head));
	for (i=1;i<=n;i++) {
		scanf("%d",&d[i]);
		if (d[i]==-1) cnt++; else sum+=d[i];
	}
	for (i=1;i<=m;i++) {
		scanf("%d%d",&x,&y);
		addedge(x,y);
	}
	if (sum%2&&cnt==0) {
		cout << -1;return 0;
	} else {
		for (i=1;i<=n;i++) 
			if (d[i]==-1) 
				if (sum%2) d[i]=1,sum++; else d[i]=0;
	}
	mem0(visit);
	mem0(f);
	sum=0;
	dfs(1,-1,-1);
	printf("%d\n",sum);
	for (i=1;i<=m;i++) 
		if (f[i]) printf("%d ",i);
	return 0;
}

