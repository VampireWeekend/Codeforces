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
const int maxn=100005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
ll a[maxn];

int main() {
	ll n,k,i,j,ans=-1;
	scanf("%I64d%I64d",&n,&k);
	for (i=1;i<=k;i++) {
		scanf("%I64d",&a[i]);
		ll now;
		now=n/a[i]*a[i];
		if (now>ans) {
			ans=now;j=i;
		}
	}
	printf("%I64d %I64d",j,n/a[j]);
	return 0;
}
