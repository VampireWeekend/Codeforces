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
const int maxn=25,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
ll a[maxn],b[maxn];

int main() {
	int n=14,i,j;
	for (i=1;i<=n;i++) {
		scanf("%I64d",&a[i]);
	}
	ll ans=-llinf;
	for (i=1;i<=n;i++) {
		if (a[i]<=0) continue;
		for (j=1;j<=n;j++) b[j]=a[j];
		b[i]=0;
		for (j=i+1;j<=n;j++) {
			b[j]+=a[i]/14;
			if (a[i]%14>=j-i) b[j]++;
		}
		for (j=1;j<=i;j++) {
			b[j]+=a[i]/14;
			if (a[i]%14>=n-i+j) b[j]++;
		}
		ll sum=0;
		for (j=1;j<=n;j++) {
			if (b[j]%2==0) sum+=b[j];
		}
		ans=max(ans,sum);
	}
	printf("%I64d\n",ans);
	return 0;
}
