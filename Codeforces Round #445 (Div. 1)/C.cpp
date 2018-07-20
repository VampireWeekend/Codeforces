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
const int maxn=1000005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f,mod=1e9+7;   
const ld pi=acos(-1.0L);
ll inv[maxn],fac[maxn],dp[maxn],sum[maxn];

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

int main() {
	ll n,k,ans=0,i;
	cin >> n >> k;
	if (n<=k+1) {
		printf("0\n");return 0;
	}
	fac[0]=1;
	for (i=1;i<=n;i++) {
		fac[i]=(fac[i-1]*i)%mod;
	}
	inv[n]=fastpow(fac[n],mod-2);  
    for (i=n-1;i>=0;i--) {  
        inv[i]=inv[i+1]*(i+1);  
        inv[i]%=mod;  
    }
    mem0(dp);mem0(sum);
    for (i=k+2;i<=n;i++) {
    	dp[i]=(i-k-1+(sum[i-1]-sum[i-k-1]+mod)%mod)%mod;
    	dp[i]=(dp[i]*fac[i-2])%mod;
    	sum[i]=sum[i-1]+(dp[i]*inv[i-1])%mod;
    	sum[i]%=mod;
    	ans+=(((dp[i]*fac[n-1])%mod)*inv[i-1])%mod;
    	ans%=mod;
    }
    cout << ans;
	return 0;
}
