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
const int maxn=61,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int dp[maxn][maxn][1005],a[maxn][maxn][maxn];

int main() {
	int n,m,q,i,j,k,l,x,y,z;
	scanf("%d%d%d",&n,&m,&q);
	for (l=1;l<=m;l++) {
		for (i=1;i<=n;i++) 
			for (j=1;j<=n;j++) 
				scanf("%d",&a[l][i][j]);
		for (i=1;i<=n;i++) 
			for (j=1;j<=n;j++) {
				if (i==j) continue;
				for (k=1;k<=n;k++) {
					if (i==k||j==k) continue;
					a[l][j][k]=min(a[l][j][k],a[l][j][i]+a[l][i][k]);
				}
			}
	}
	meminf(dp);
	for (l=1;l<=m;l++) 
		for (i=1;i<=n;i++) 
			for (j=1;j<=n;j++) 
				for (k=1;k<=n;k++) 
					dp[j][k][0]=min(dp[j][k][0],a[l][j][i]+a[l][i][k]);
	for (l=1;l<=n;l++) 
		for (i=1;i<=n;i++) 
			for (j=1;j<=n;j++) 
				for (k=1;k<=n;k++) 
				    dp[j][k][l]=min(dp[j][k][l],dp[j][i][l-1]+dp[i][k][0]);
	for (i=1;i<=q;i++) {
		scanf("%d%d%d",&x,&y,&z);
		if (z>n) z=n;
		printf("%d\n",dp[x][y][z]);
	}
	return 0;
}

