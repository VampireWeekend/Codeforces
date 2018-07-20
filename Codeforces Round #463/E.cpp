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

ll fastpow(ll base,ll index) {  
    ll sum=base,ans=1;  
    ll i=index;  
    while (i) {  
        if (i%2) ans=(ans*sum)%mod;  
        sum*=sum;  
        sum=sum%mod;  
        i/=2;  
    }  
    return ans;  
}

ll solve(ll k,ll n,ll a,ll b) {
	if (dp[k][a]!=-1) return dp[k][a];
	if (k==0) return dp[k][a]=fastpow(2,b);
	return dp[k][a]=((b==0?0LL:b*solve(k-1,n,a+1,b-1)%mod)
			+(a==0?0LL:a*solve(k-1,n,a,b)%mod))%mod;
}

int main() {
	ll n,k;
	scanf("%I64d%I64d",&n,&k);
	memset(dp,-1,sizeof(dp));
	ll ans=solve(k,n,0,n);
	printf("%I64d\n",ans);
	return 0;
}
