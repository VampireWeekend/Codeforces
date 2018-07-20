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
const int maxn=1005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int dp[maxn][maxn];
int w[maxn],val[maxn];
bool visit[maxn];
vector<int> v[maxn],l;
int num=0,wn,vn;

void dfs(int now) {
	l.push_back(now);
	visit[now]=1;
	wn+=w[now];vn+=val[now];
	for (int i=0;i<v[now].size();i++) {
		int to=v[now][i];
		if (!visit[to]) dfs(to);
	}
}

int main() {
	int n,m,mw,x,y,i,j,k;
	scanf("%d%d%d",&n,&m,&mw);
	for (i=1;i<=n;i++) scanf("%d",&w[i]);
	for (i=1;i<=n;i++) scanf("%d",&val[i]);
	for (i=1;i<=m;i++) {
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	mem0(visit);
	for (i=1;i<=n;i++) {
		if (!visit[i]) {
			l.clear();
			num++;
			wn=vn=0;
			dfs(i);
			for (k=mw;k>=0;k--) dp[num][k]=dp[num-1][k];
			for (j=0;j<l.size();j++) {
				int r=l[j];
				for (k=mw;k>=w[r];k--)
					dp[num][k]=max(dp[num][k],dp[num-1][k-w[r]]+val[r]);
			}
			for (k=mw;k>=wn;k--)
				dp[num][k]=max(dp[num][k],dp[num-1][k-wn]+vn);
		}
	}
	printf("%d\n",dp[num][mw]);
	return 0;
}
