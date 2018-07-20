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
const int maxn=3005, maxk=400005, inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f3f3f;
const ld pi = acos(-1.0L);
int head[maxn], ans[maxk], dfn[maxn], low[maxn];
bool inst[maxn];
vector<int> v[maxn],c[maxn];
int st[maxn],top,s,t;
int num;

struct query {
	int id, x, y, k;
};
query q[maxk];

bool cmp(query a,query b) {
	return a.x < b.x;
}

void tarjan(int now,int step,bool cyc) {
	num++;
	dfn[now] = num; low[now] = inf;
	inst[now] = 1;
	st[++top] = now;
	if (cyc) {
		for (int i = 0; i < c[now].size(); i++)
			if (q[c[now][i]].k <= step) ans[q[c[now][i]].id] = st[q[c[now][i]].k];
	}
	for (int i = 0; i<v[now].size(); i++) {
		int to = v[now][i];
		if (!dfn[to]) {
			tarjan(to,step+1,cyc&&dfn[now]<low[now]);
			low[now] = min(low[now], low[to]);
		}
		else if (inst[to])
			low[now] = min(low[now], dfn[to]);
	}
	inst[now] = 0;
	top--;
}

int main() {
	int n, m, k,i,j,x,y;
	scanf("%d%d%d", &n, &m, &k);
	for (i = 1; i <= m; i++) {
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
	}
	for (i = 1; i <= n; i++) 
		sort(v[i].begin(), v[i].end());
	for (i = 1; i <= k; i++) {
		scanf("%d%d%d", &q[i].x, &q[i].y, &q[i].k);
		q[i].id = i;
	}
	sort(q + 1, q + k + 1, cmp);
	memset(ans, -1, sizeof(ans));
	num = 0;
	mem0(dfn); mem0(low); mem0(inst);
	m = 1;
	for (i = 1; i <= n; i++) {
		if (q[m].x == i) {
			num = top = 0;
			while (q[m].x == i&&m <= k) {
				c[q[m].y].push_back(m);
				m++;
			}
			mem0(dfn); mem0(low); mem0(inst);
			tarjan(i,1,1);
			for (j = 1; j <= n; j++) c[j].clear();
		}
	}
	for (i = 1; i <= k; i++) printf("%d\n", ans[i]);
//	system("pause");
	return 0;
}
