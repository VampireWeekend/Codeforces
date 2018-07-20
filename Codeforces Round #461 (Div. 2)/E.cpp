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
const int maxn=1005,maxk=10005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
ll a[maxn],c[maxn];
ll dp[maxn][maxk];

int main() {
	ll n,w,b,x,i,j,k;
	scanf("%I64d%I64d%I64d%I64d",&n,&w,&b,&x);
	for (i=1;i<=n;i++) 
		scanf("%I64d",&a[i]);
	for (i=1;i<=n;i++) 
		scanf("%I64d",&c[i]);
	memset(dp,-1,sizeof(dp));
	dp[0][0]=w;
	ll sum=0;
	for (i=1;i<=n;i++) {
		sum+=a[i];
		ll cap=w;
		for (j=0;j<=sum;j++) {
			for (k=0;k<=a[i]&&k<=j;k++) {
				if (dp[i-1][j-k]==-1) continue;
				if (k*c[i]>dp[i-1][j-k]) continue;
				dp[i][j]=max(dp[i][j],dp[i-1][j-k]-k*c[i]);
			}
			if (dp[i][j]!=-1) dp[i][j]=min(dp[i][j]+x,cap);
			cap+=b;
		}
	}
	ll ans=0;
	for (i=0;i<=sum;i++)
		if (dp[n][i]!=-1) ans=i;
	printf("%I64d\n",ans);
	return 0;
}
