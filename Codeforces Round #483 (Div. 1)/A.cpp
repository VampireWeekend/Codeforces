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
const int maxn=5005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
ll dp[maxn][maxn],a[maxn]; 

int main() {
	int n,i,j,q;
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		scanf("%I64d",&a[i]);
		dp[1][i]=a[i];
	}
	scanf("%d",&q);
	for (i=2;i<=n;i++) {
		for (j=1;j<=n-i+1;j++) {
			dp[i][j]=dp[i-1][j]^dp[i-1][j+1];
		}
	}
	for (i=2;i<=n;i++) {
		for (j=1;j<=n-i+1;j++) {
			dp[i][j]=max(max(dp[i-1][j],dp[i-1][j+1]),dp[i][j]);
		}
	}
	int l,r;
	for (i=1;i<=q;i++) {
		scanf("%d%d",&l,&r);
		printf("%I64d\n",dp[r-l+1][l]);
	}
	return 0;
}
