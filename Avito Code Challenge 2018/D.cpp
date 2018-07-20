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
const int maxn=55,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
ll a[maxn],s[maxn];
bool dp[maxn][maxn];

int main() {
	ll n,k,i,j,l,p;
	scanf("%I64d%I64d",&n,&l);
	ll ans=0;
	for (i=1;i<=n;i++) {
		scanf("%I64d",&a[i]);
		s[i]=s[i-1]+a[i];
	}
	for (i=57;i>=0;i--) {
		mem0(dp);
		ll now=ans+(1ll<<i);
		for (j=1;j<=n;j++) {
			if ((s[j]&now)==now) dp[1][j]=1;
		}
		for (j=2;j<=l;j++) {
			for (k=j;k<=n;k++) {
		//		ll sum=0;
				for (p=j-1;p<k;p++) {
					if (!dp[j-1][p]) continue;
					if (((s[k]-s[p])&now)==now) dp[j][k]=1;
				}
			}
		}
		if (dp[l][n]) ans+=(1ll<<i);
	}
	printf("%I64d\n",ans);
	return 0;
}
