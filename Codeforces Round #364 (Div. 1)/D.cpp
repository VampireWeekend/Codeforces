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
const int maxn = 100005, inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f3f3f;
const ld pi = acos(-1.0L);
int a[maxn], cnt[maxn], fre[maxn], fr[maxn];
ll ans[maxn];
vector<int> v;

struct query {
	int l, r, id, k;
};
query q[maxn];

bool cmp(query a, query b) {
	return a.k < b.k || (a.k == b.k&&a.r < b.r);
}

void update(int pos, int val) {
	fre[cnt[pos]]--;
	cnt[pos] += val;
	fre[cnt[pos]]++;
}

int main() {
	int n, i, j, k, m, l, r;
	scanf("%d", &n);
	mem0(cnt);mem0(ans);
	int size = sqrt(n) + 1;
	for (i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		cnt[a[i]]++;
		if (cnt[a[i]] == size) v.push_back(a[i]);
	}
	scanf("%d", &m);
	for (i = 1; i <= m; i++) {
		scanf("%d%d", &q[i].l, &q[i].r);
		q[i].id = i; q[i].k = q[i].l / size;
	}
	sort(q + 1, q + m + 1, cmp);
	l = 1; r = 0;
	mem0(cnt); mem0(fre);
	fre[0] = n;
	for (i = 1; i <= m; i++) {
		while (l < q[i].l) update(a[l], -1), l++;
		while (l > q[i].l) l--, update(a[l], 1);
		while (r > q[i].r) update(a[r], -1), r--;
		while (r < q[i].r) r++, update(a[r], 1);
		priority_queue<int, vector<int>, greater<int> > pq;
		memcpy(fr,fre,sizeof(int)*(size+5));
		ans[q[i].id] = 0;
		for (j = 0; j < v.size(); j++) if (cnt[v[j]] >= size) pq.push(cnt[v[j]]);
		int last = 0;
		for (j = 1; j < size; j++) {
			if (fr[j] > 0) {
				if (last) {
					fr[j]--; ans[q[i].id] += (ll)(last + j);
					if (last + j < size) fr[last + j]++; else pq.push(last + j);
					last = 0;
				}
				if (fr[j] % 2 == 1) fr[j]--, last = j;
				ans[q[i].id] += fr[j]*j;
				if (2 * j >= size)
					for (k = 1; k <= fr[j] / 2; k++) pq.push(j * 2);
				else fr[j * 2] += fr[j] / 2;
			}
		}
		if (last) pq.push(last);
		while (pq.size() > 1) {
			int b = pq.top(); pq.pop();
			int c = pq.top(); pq.pop();
			ans[q[i].id] += (ll)(b + c);
			pq.push(b + c);
		}
	}
	for (i = 1; i <= m; i++) printf("%I64d\n", ans[i]);
	return 0;
}
