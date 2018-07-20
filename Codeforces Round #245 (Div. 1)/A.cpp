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
const int maxn=100005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int head[maxn],a[maxn],b[maxn];
bool visit[maxn];
int num,ans;
vector<int> v;

struct Edge {
	int from, to, pre;
};
Edge edge[maxn*2];

void addedge(int from, int to) {
	edge[num] = (Edge) {from, to, head[from]};
	head[from] = num++;
	edge[num] = (Edge) {to, from, head[to]};
	head[to] = num++;
}

void dfs(int now,int s1,int s2) {
	visit[now]=1;
	int flag=0;
	if (a[now]^s2!=b[now]) ans++,flag=1,v.push_back(now);
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to])
			dfs(to,s2^flag,s1);
	}
}

int main() {
	int n,x,y,i,j;
	scanf("%d",&n);
	num=0;
	memset(head,-1,sizeof(head));
	for (i=1;i<n;i++) {
		scanf("%d%d",&x,&y);
		addedge(x,y);
	}
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	for (i=1;i<=n;i++) scanf("%d",&b[i]);
	mem0(visit);ans=0;
	dfs(1,0,0);
	printf("%d\n",ans);
	for (i=0;i<v.size();i++) {
		printf("%d\n",v[i]);
	}
	return 0;
}
