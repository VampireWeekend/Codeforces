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
const int maxn=100005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);
int head[maxn],s[maxn];
int num=0,ans=0;
bool visit[maxn];

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
	s[now]++;
	visit[now]=1;
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to]) 
			dfs(to),s[now]+=s[to];
	}
	if (s[now]%2==0) ans++,s[now]=0;
}

int main() {
	num=0;mem0(visit);
	memset(head,-1,sizeof(head));
	int n,i,x,y;
	scanf("%d",&n);
	for (i=1;i<n;i++) {
		scanf("%d%d",&x,&y);
		addedge(x,y);
	}
	if (n%2) {
		printf("-1");
		return 0;
	}
	dfs(1);
	printf("%d",ans-1);
	return 0;
}

