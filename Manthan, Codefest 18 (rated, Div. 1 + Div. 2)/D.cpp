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
#include <assert.h>
#define pb push_back 
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef pair<int,int> pp;
const int maxn=200005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
int head[maxn],a[maxn],sz[maxn],fa[maxn],dep[maxn];
int l[maxn],r[maxn];
int num=0;
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

void dfs(int now,int f,int d) {
	sz[now]=0;
	visit[now]=1;
	fa[now]=f;dep[now]=d;
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to]) 
			dfs(to,now,d+1),sz[now]++;
	}
}

int main() {
	int n,x,y,m;
	num=0;mem0(visit);
	memset(head,-1,sizeof(head));
	scanf("%d",&n);
	for (int i=1;i<n;i++) {
		scanf("%d%d",&x,&y);
		addedge(x,y);
	}
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	dfs(a[1],0,1);
	m=1;l[1]=1;
	for (int i=2;i<=n;i++) {
		if (dep[a[i]]<dep[a[i-1]]) {
			printf("No");return 0;
		}
		if (dep[a[i]]>dep[a[i-1]]+1) {
			printf("No");return 0;
		}
		if (dep[a[i]]==dep[a[i-1]]+1) {
			m++;
			r[m-1]=i-1;l[m]=i;
		}
	}
	r[m]=n;
	for (int i=2;i<m;i++) {
		int q=l[i+1];
		for (int j=l[i];j<=r[i];j++) {
			for (int k=1;k<=sz[a[j]];k++) {
				if (fa[a[q]]!=a[j]) {
					printf("No");return 0;
				}
				q++;
			}
		}
	}
	printf("Yes");
	return 0;
}
