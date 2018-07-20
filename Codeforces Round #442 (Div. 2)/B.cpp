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
const int maxn=5005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int dp[maxn][3];
char s[maxn];

int main() {
	scanf("%s",s+1);
	int i,j,len,ans=0;
	len=strlen(s+1);
	mem0(dp);
	for (i=1;i<=len;i++) {
		if (s[i]=='a') dp[i][0]=dp[i-1][0]+1; else dp[i][0]=dp[i-1][0];
		ans=max(ans,dp[i][0]);
	}
	for (i=1;i<=len;i++) {
		if (s[i]=='b') dp[i][1]=max(dp[i-1][1],dp[i-1][0])+1; else dp[i][1]=max(dp[i][0],dp[i-1][1]);
		ans=max(ans,dp[i][1]);
	}
	for (i=1;i<=len;i++) {
		if (s[i]=='a') dp[i][2]=max(dp[i-1][1],dp[i-1][2])+1; else dp[i][2]=max(dp[i][1],dp[i-1][2]);
		ans=max(ans,dp[i][2]);
	}
	printf("%d\n",ans);
	return 0;
}
