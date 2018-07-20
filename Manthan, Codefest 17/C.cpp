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
typedef double db;
const int maxn=100005, inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f3f3f,mod=1000000007;
const ld pi = acos(-1.0L);
vector<int> v[maxn];
ll dp[maxn][11][3],a[maxn][11][3];
bool visit[maxn];
int n;
ll m, p, x;

void dfs(int now) {
	visit[now] = 1;
	int size = v[now].size(),i,j,k,last=-1;
	dp[now][1][0] = 1; dp[now][0][1] = p - 1; dp[now][0][2] = m - p;
	for (i = 0; i < size; i++) {
		int to = v[now][i];
		if (!visit[to]) {
			dfs(to);
			for (j = 0; j <= x; j++) {
				for (k = 0; k <= 2;k++) {
					a[now][j][k] = 0;
				}
			}
			for (j = 0; j <= x; j++) {
				for (k = j; k >= 0;k--) {
					if (j != 0&&k!=0) a[now][j][0] += dp[to][j - k][1]*dp[now][k][0];
					a[now][j][1]+=((dp[to][j-k][0]+dp[to][j-k][1]+dp[to][j-k][2])*dp[now][k][1])%mod;
					a[now][j][2] += ((dp[to][j-k][1] + dp[to][j-k][2])*dp[now][k][2]) % mod;
					a[now][j][1] %= mod; a[now][j][2] %= mod; a[now][j][0] %= mod;
				}
			}
			for (j = 0; j <= x; j++) {
				for (k = 0; k <= 2;k++) {
					dp[now][j][k] = a[now][j][k];
				}
			}
		}
	}
}

int main() {
	int s,t,i,j,f;
	scanf("%d%I64d", &n, &m);
	for (i = 1; i < n; i++) {
		scanf("%d%d", &s, &t);
		v[s].push_back(t);
		v[t].push_back(s);
	}
	scanf("%I64d%I64d", &p, &x);
	mem0(dp); mem0(visit);
	dfs(1);
	ll sum = 0;
	for (i = 0; i <= x; i++) {
		for (j = 0; j <= 2; j++) {
	//		if (i == 0 && j == 0) continue;
			sum += dp[1][i][j];
			sum %= mod;
		}
	}
	/*for (i = 1; i <= n; i++) {
		for (j = 0; j <= x; j++) {
			for (f = 0; f <= 2; f++) printf("%d %d %d %lld\n", i, j, f, dp[i][j][f]);
		}
	}*/
	printf("%I64d\n", sum);
//	system("pause");
	return 0;
}
