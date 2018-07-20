#include <cstdio>
#include <iostream>
#include <string.h>
#include <string> 
#include <unordered_map>
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
typedef double db;
const int maxn = 1000005, inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f3f3f;
ll a[maxn], b[maxn], c[25];
int na = 0, nb = 0;

void dfs(int l, int r, int num, ll now) {
	if (num == 0) a[++na] = now; else b[++nb] = now;
	for (int i = l; i <= r; i++) {
		if (c[i] <= 1000000000000000000 / now) {
			dfs(i, r, num, now*c[i]);
		}
	}
}

bool check(ll mid, ll k) {
	ll sum = 0;
	for (int i = 1; i <= na; i++) {
		if (a[i] > mid) continue;
		int pos = upper_bound(b + 1, b + nb + 1, mid / a[i]) - b - 1;
		sum += (ll)pos;
	}
	if (sum >= k) return true; else return false;
}

int main() {
	ll n, k, i;
	scanf("%I64d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%I64u", &c[i]);
	}
	scanf("%I64d", &k);
	dfs(1, min(6ll, n - 1), 0, 1);
	dfs(min(6ll, n - 1) + 1, n, 1, 1);
	sort(b + 1, b + nb + 1);
	ll ans = 1, l, r;
	l = 1; r = 1e18 + 5;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (check(mid, k)) ans = mid, r = mid - 1; else l = mid + 1;
	}
	cout << ans << endl;
	//	system("pause");
	return 0;
}