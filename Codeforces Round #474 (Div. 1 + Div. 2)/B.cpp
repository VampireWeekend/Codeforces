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
ll a[maxn],b[maxn];

int main() {
	ll n,k1,k2,i,j;
	scanf("%I64d%I64d%I64d",&n,&k1,&k2);
	for (i=1;i<=n;i++) scanf("%I64d",&a[i]);
	for (i=1;i<=n;i++) scanf("%I64d",&b[i]);
	while (k1||k2) {
		ll p=1;
		for (i=2;i<=n;i++) {
			if (abs(a[i]-b[i])>abs(a[p]-b[p])) p=i;
		}
		if (a[p]>b[p]) {
			if (k1) a[p]--,k1--; else b[p]++,k2--;
		} else {
			if (k1) a[p]++,k1--; else b[p]--,k2--;
		}
	}
	ll sum=0;
	for (i=1;i<=n;i++) {
		sum+=(a[i]-b[i])*(a[i]-b[i]);
	}
	printf("%I64d\n",sum);
	return 0;
}
