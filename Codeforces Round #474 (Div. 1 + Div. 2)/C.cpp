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
const int maxn=10005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
ll a[maxn],b[maxn];

int main() {
	ll x,d,n=0,i,j,ba=1;
	scanf("%I64d%I64d",&x,&d);
	b[0]=0;
	for (i=1;i<=60;i++) {
		b[i]=(b[i-1]+1ll)*2ll-1ll;
	}
	for (i=60;i>=1;i--) {
		while (x>=b[i]) {
			for (j=1;j<=i;j++) a[++n]=ba;
			x-=b[i];ba+=d;
		}
	}
	if (n>10000) {
		cout << -1;return 0;
	}
	printf("%I64d\n",n);
	for (i=1;i<=n;i++) printf("%I64d ",a[i]);
	return 0;
}
