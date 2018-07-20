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
const int maxn=200005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f,mod=1e9+7; 
const ld pi=acos(-1.0L);
int head[maxn];
ll a[maxn],dp[maxn][2],size[maxn],dp2[maxn][2];
int num=0;
ll ans=0,n;
int visit[maxn];

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
	visit[now]=1;size[now]=0;
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to]) {
			dfs(to);
			visit[to]=2;
			dp[now][0]+=dp[to][1];dp[now][1]+=dp[to][0];
			size[now]+=size[to];
		}
	}
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (visit[to]==2) {
			ans+=(((size[now]-size[to])*a[now])%mod)*(dp[to][1]-dp[to][0]);
			ans%=mod;
			visit[to]++;
		} 
	}
	ans+=((dp[now][0]-dp[now][1])*a[now]%mod)*(n-size[now]);
	ans%=mod;
	dp[now][0]++;
//	cout << now << ' ' << ans << endl;
	size[now]++;
}

void dfs2(int now) {
	visit[now]=1;
	if (now!=1) ans+=((size[now]*a[now])%mod)*(dp2[now][0]-dp2[now][1]);
	ans%=mod;
//	cout << now << ' ' << ans << endl;
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to]) {
			dp2[to][0]=dp[now][1]-dp[to][0]+dp2[now][1];
			dp2[to][1]=dp[now][0]-dp[to][1]+dp2[now][0];
			dfs2(to);
		}
	}
	ans+=n*a[now];
	ans%=mod;
}

int main() {
	num=0;mem0(visit);
	memset(head,-1,sizeof(head));
	int i,j,x,y;
	scanf("%I64d",&n);
	for (i=1;i<=n;i++) scanf("%I64d",&a[i]);
	for (i=1;i<n;i++) {
		scanf("%d%d",&x,&y);
		addedge(x,y);
	}
	mem0(visit);
	dfs(1);
	mem0(visit);
	dfs2(1);
	ans=(ans+mod)%mod;
	printf("%I64d\n",ans);
	return 0;
}
