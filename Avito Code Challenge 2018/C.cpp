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
#define pb push_back 
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=100005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
int head[maxn],s[maxn];
int num=0;
bool visit[maxn];
vector<int> v,l;

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
	s[now]=0;
	if (now!=1) s[now]++;
	visit[now]=1;
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to]) 
			dfs(to),s[now]++;
	}
	if (s[now]==1) l.pb(now);
//	if (s[now]>1&&now!=1) v.pb(now);
}

int main() {
	int n,i,j,x,y;
	num=0;mem0(visit);
	memset(head,-1,sizeof(head));
	scanf("%d",&n);
	for (i=1;i<n;i++) {
		scanf("%d%d",&x,&y);
		addedge(x,y);
	}
	if (n==2) {
		printf("Yes\n1\n1 2\n");
		return 0;
	}
	dfs(1);
	for (i=1;i<=n;i++) {
		if (s[i]==l.size()) {
			printf("Yes\n%d\n",l.size());
			for (j=0;j<l.size();j++) printf("%d %d\n",i,l[j]);
			return 0;
		}
	}
	printf("No\n");
	return 0;
}
