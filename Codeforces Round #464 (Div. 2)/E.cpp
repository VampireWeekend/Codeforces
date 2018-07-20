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
const int maxn=500005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
ll a[maxn],sum[maxn];

int main() {
	ll n,i,q,m;
	int x;
	n=m=sum[0]=0;
	db ans=0;
	scanf("%I64d",&q);
	for (i=1;i<=q;i++) {
		scanf("%d",&x);
		if (x==1) {
			n++;
			scanf("%I64d",&a[n]);
			sum[n]=sum[n-1]+a[n];
		} else {
			if (n==1) ans=0; else ans=(db)a[n]-(db)(sum[m]+a[n])/(db)(m+1);
			while (m+1<n&&(db)a[n]-(db)(sum[m+1]+a[n])/(db)(m+2)>ans) {
				ans=(db)a[n]-(db)(sum[m+1]+a[n])/(db)(m+2);
				m++;
			}
			printf("%.10lf\n",ans);
		}
	}
	return 0;
}
