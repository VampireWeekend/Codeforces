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
#define pb push_back 
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=100005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);

int main() {
	int n,i,j,x,a,b;
	scanf("%d",&n);
	scanf("%d%d",&a,&b);
	x=max(a,b);
	for (i=2;i<=n;i++) {
		scanf("%d%d",&a,&b);
		if (a>b) swap(a,b);
		if (b<=x) x=min(x,b); else {
			if (x>=a) x=min(x,a); else {
				printf("no");
				return 0;
			}
		}
	}
	printf("yes");
	return 0;
}
