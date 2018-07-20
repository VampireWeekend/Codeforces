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
int head[maxn],size[maxn];
bool visit[maxn],col[maxn];
int num,k;
ll ans;

struct Edge {
	int from,to,pre;
};
Edge edge[maxn*2];

void addedge(int from, int to) {
	edge[num]=(Edge){from,to,head[from]};
	head[from]=num++;
	edge[num]=(Edge){to,from,head[to]};
	head[to]=num++;
}

void dfs(int now) {	
	visit[now]=1;
	size[now]=0;
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to]) {
			dfs(to);
			size[now]+=size[to];
		}
	}
	if (col[now]) size[now]++;
	if (now!=1) 
		if (size[now]<=k) ans+=(ll)size[now]; else ans+=(ll)(2*k-size[now]); 
}

int main() {
	int n,i,j,x,y;
	num=ans=0;
	scanf("%d%d",&n,&k);
	mem0(col);
	memset(head,-1,sizeof(head));
	for (i=1;i<=2*k;i++) {
		scanf("%d",&x);
		col[x]=1;
	}
	for (i=1;i<n;i++) {
		scanf("%d%d",&x,&y);
		addedge(x,y);
	}
	ans=0;mem0(visit);
	dfs(1);
	printf("%I64d\n",ans);
	return 0;
}
