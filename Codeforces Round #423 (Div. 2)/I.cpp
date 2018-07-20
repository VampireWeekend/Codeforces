#include <cstdio>
#include <iostream>
#include <vector>
#include <string.h>
#include <map>
#include <algorithm>
#include <set>
#include <math.h>
#include <cmath>
#include <queue>
using namespace std;
typedef long long ll;
const int maxn=2000;
const ll mod=1000000007;
ll dp[2005][4];

int main() {
	int t,i,j;
	scanf("%d",&t);
	memset(dp,0,sizeof(dp));
	dp[1][1]=dp[1][0]=26;
	for (i=2;i<=2000;i++) {
		dp[i][1]=dp[i-1][0]*25;
		dp[i][1]%=mod;
		dp[i][2]=dp[i-1][1];
		dp[i][2]%=mod;
		dp[i][3]=dp[i-1][2];
		dp[i][3]%=mod;
		dp[i][0]=dp[i][1]+dp[i][2]+dp[i][3];
		dp[i][0]%=mod;
	}
	int x;
	for (i=1;i<=t;i++) {
		scanf("%d",&x);
		printf("%lld\n",dp[x][0]);
	}
	return 0;
}
