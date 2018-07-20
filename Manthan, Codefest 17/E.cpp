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
#include <iomanip>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f3f3f;
const ld pi = acos(-1.0L);
ll dp[64][11][2048];
ll num[100];

ll dfs(int len, int b, int con, bool zero, bool HaveLimit) {
	if (len == 0)
		return con == 0 && !zero;
	if (dp[len][b][con] != -1 && !HaveLimit&&!zero)
		return dp[len][b][con];

	int p = HaveLimit ? num[len] : b - 1;
	ll ans = 0;
	for (int i = 0; i <= p; i++) {
		if (zero&&i == 0)
			ans += dfs(len - 1, b, con, 1, HaveLimit&&i == num[len]);
		else
			ans += dfs(len - 1, b, con ^ (1 << i), 0, HaveLimit&&i == num[len]);
	}
	if (!HaveLimit&&!zero)
		dp[len][b][con] = ans;
	return ans;
}

ll solve(ll n, ll b) {
	if (n == 0) return 0;
	int len = 0, i;
	ll k = n;
	while (k) {
		num[++len] = k % b;
		k /= b;
	}
	ll ans = 0;
	ans = dfs(len, (int)b, 0, 1, 1);
	return ans;
}

int main() {
	int cas;
	scanf("%d", &cas);
	ll l, r, ans, b;
	memset(dp, -1, sizeof(dp));
	while (cas--) {
		scanf("%I64d%I64d%I64d", &b, &l, &r);
		ans = solve(r, b) - solve(l - 1, b);
		printf("%I64d\n", ans);
	}
//	system("pause");
	return 0;
}
