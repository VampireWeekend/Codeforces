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
#include <unordered_map>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=100005, inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f3f3f;
const ld pi = acos(-1.0L);

int main() {
	int n, l, r, mid,last,i,now,p0,p1,tot,q;
	scanf("%d", &n);
	l = 1; r = n;
	printf("? ");
	for (i = 1; i <= n; i++) 
		printf("0");
	printf("\n");
	fflush(stdout);
	scanf("%d", &tot);
	mid = p0 = p1 = -1;
	printf("? 1");
	for (i = 1; i < n; i++)
		printf("0");
	printf("\n");
	fflush(stdout);
	scanf("%d", &q);
	if (q == tot + 1) p0 = 1; else p1 = 1;
	while (l < r) {
		mid = (l + r+1) / 2;
		printf("? ");
		for (i = 1; i < mid; i++) printf("0");
		for (i = mid; i <= r; i++) printf("1");
		for (i = r + 1; i <= n; i++) printf("0");
		printf("\n");
		fflush(stdout);
		scanf("%d", &now);
		if (p0 == 1) {
			if (now == tot - (r - mid + 1)) {
				p1 = mid;
				break;
			}
			else if (now == tot + (r - mid + 1)) r = mid - 1; else l = mid;
		} else 
			if (now == tot + (r - mid + 1)) {
				p0 = mid, r = mid - 1;
				break;
			}
			else if (now == tot - (r - mid + 1)) r = mid - 1; else l = mid;
	}
	if (p0 == -1) p0 = mid - 1;
	if (p1 == -1) p1 = mid - 1;
	printf("! %d %d\n", p0, p1);
	system("pause");
	return 0;
}
