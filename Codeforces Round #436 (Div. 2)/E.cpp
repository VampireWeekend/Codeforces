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
const int maxn=2005, inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f3f3f;
const ld pi = acos(-1.0L);
int dp[maxn], cnt[maxn];
ll b[105];
ll con[maxn][2];

struct khalid {
	int t, d, val, id;
};
khalid a[105],p[105];

bool cmp(khalid a, khalid b) {
	return a.d < b.d ;
}

int main() {
	mem0(dp); mem0(cnt);
	mem0(con);
	int n, i, j, ans, k;
	stack<int> st;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d%d%d", &a[i].t, &a[i].d, &a[i].val);
		a[i].id = i;
	}
	b[0] = 1;
	for (i = 1; i <= 51; i++) {
		b[i] = b[i - 1] * (ll)2;
	}
	sort(a + 1, a + n + 1, cmp);
	for (i = 1; i <= n; i++) {
		for (j = a[i].d-1; j >= a[i].t; j--) {
			if (dp[j] < dp[j - a[i].t] + a[i].val) {
				dp[j] = dp[j - a[i].t] + a[i].val;
				cnt[j] = cnt[j - a[i].t] + 1;
				if (i <= 50) {
					con[j][0] = con[j - a[i].t][0] ^ b[i-1];
					con[j][1] = con[j - a[i].t][1];
				}
				else {
					con[j][1] = con[j - a[i].t][1] ^ b[i-51];
					con[j][0] = con[j - a[i].t][0];
				}
			}
		}
	}
	ans = 0;
	for (i = 0; i <= 2000; i++) {
		if (dp[i] > dp[ans]) 
			ans = i;
	}
	printf("%d\n%d\n",dp[ans],cnt[ans]);
	int m = 0;
//	printf("%lld %lld\n", con[ans][0], con[ans][1]);
	for (i = 1; i <= 50; i++) {
		if ((con[ans][0] >> i - 1) % 2 == 1) p[++m].id = a[i].id,p[m].d=a[i].d;
		if ((con[ans][1] >> i - 1) % 2 == 1) p[++m].id = a[50+i].id, p[m].d = a[i+50].d;
	}
	sort(p + 1, p + m + 1, cmp);
	for (i = 1; i <= m; i++) {
		printf("%d ", p[i].id);
	}
//	system("pause");
	return 0;
}
