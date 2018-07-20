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
const ll llinf=0x3f3f3f3f3f3f3f3f,mod=1e9+7;   
const ld pi=acos(-1.0L);
ll dp[maxn][maxn];

int main() {
	int n,i,j,maxd=0,dep,cnt=1,flag=0,md=0;
	char c;
	scanf("%d",&n);getchar();
	dep=0;
	dp[0][0]=1;
	for (i=1;i<=n;i++) {
		scanf("%c",&c);
		getchar();
		if (c=='s') {
	//		if (cnt==0) continue;
				ll sum=0; 
				for (j=md+dep;j>=dep;j--) {
					sum+=dp[cnt-1][j-dep];sum%=mod;
					dp[cnt][j]=sum;
				}
				flag=dep=0;cnt++;
		} else {
		//	if (!flag) cnt++,flag++;
			dep++;
			md++;
		}
	}
	ll ans=0;
	for (i=0;i<=md;i++) {
		ans=(ans+dp[cnt-1][i])%mod;
	}
	cout << ans;
	return 0;
}
