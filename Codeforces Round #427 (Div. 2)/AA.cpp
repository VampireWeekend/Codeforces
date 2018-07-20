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
#include <bitset>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=105,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);

int main() {
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		int n,m;
		scanf("%d%d",&n,&m);
		n*=2;
		int x,y;
		y=m-n;
		y/=2;
		x=(n/2)-y;
		printf("%d %d\n",y,x);
	}
	return 0;
}

