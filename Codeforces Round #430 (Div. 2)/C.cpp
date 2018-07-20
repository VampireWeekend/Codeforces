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
const int maxn=200005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);  
int num;
int head[maxn],ans[maxn],a[maxn],b[maxn],t[maxn];
bool visit[maxn];

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

int gcd(int x,int y) {
	int z;
	if (x<y) swap(x,y);
	while (y) {
		z=y;y=x%y;x=z;
	}
	return x;
}

void dfs(int now,int fa) {
	visit[now]=1;
	if (fa==1||fa==0) ans[now]=a[now]; else 
	    if (now!=1) ans[now]=gcd(ans[fa],a[now]);
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to]) 
			dfs(to,now);
	}
}

void dfs2(int now,int depth) {
	visit[now]=1;
	for (int i=1;i<=num;i++) {
		if (a[now]%b[i]==0) t[i]++;
		if (t[i]>=depth) ans[now]=max(ans[now],b[i]);
	}
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to]) 
			dfs2(to,depth+1);
	}
	for (int i=1;i<=num;i++) {
		if (a[now]%b[i]==0) t[i]--;
	}
}

int main() {
	int n,i,x,y;
	num=0;memset(head,-1,sizeof(head));
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	for (i=1;i<n;i++) {
		scanf("%d%d",&x,&y);
		addedge(x,y);
	}
	mem0(visit);
	dfs(1,0);
	num=0;
	for (i=1;i<=sqrt(a[1]);i++) {
		if (a[1]%i==0) {
			b[++num]=i;
			if ((a[1]/i)*(a[1]/i)!=a[1]) b[++num]=a[1]/i;
		}
	}
	sort(b+1,b+num+1);
	mem0(visit);visit[1]=1;
	mem0(t);
	for (i=head[1];i!=-1;i=edge[i].pre) {
		if (!visit[edge[i].to]) {
			dfs2(edge[i].to,0);
		}
	}
	for (i=1;i<=n;i++) printf("%d ",ans[i]);
	return 0;
}

