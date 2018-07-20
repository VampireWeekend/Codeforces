#include <cstdio>
#include <iostream>
#include <string.h>
#include <string> 
#include <map>
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
typedef long double ld;
typedef double db;
const int maxn=100005, inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f3f3f;
const ld pi = acos(-1.0L);
bool visit[maxn];
int num;
vector<int> v[maxn],qr[maxn];

void dfs(int now) {

}

int main() {
	int n, i, j, x, y, t, z;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d%d", &x, &y);
		if (y==0) v[x].push_back(i); else 
			if (y==1) 
	}
	num = 0;
	scanf("%d", &q);
	for (i = 1; i <= q; i++) {
		scanf("%d%d%d", &t, &x, &z);
		if (t == 1) {
			v[x].push_back(z);
		}
		else {
			qr[x].push_back(z);
		}
	}
	mem0(visit);
	dfs(1);

	return 0;
}
