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
const int maxn=1005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
bool a[maxn];

int main() {
	int b,c,n,i;
	mem0(a);
	b=c=1;
	a[1]=1;
	while (b+c<=1000) {
		a[b+c]=1;
		int u=b;b=c;c=b+u;
	}
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		if (a[i]) printf("O"); else printf("o");
	}
	return 0;
}
