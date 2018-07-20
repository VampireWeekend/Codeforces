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
const int maxn=100005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f,mod=1e9+7;   
const ld pi=acos(-1.0L);
ll dp[maxn],a[maxn],p[maxn],ans[maxn],inv[maxn],fac[maxn];
char s[maxn];
vector<ll> v[maxn],d[maxn];

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
  
ll lucas(ll n,ll m){  
    if (n<m) {  
        return 0;  
    } else return p[n]*((inv[m]%mod)*inv[n-m]%mod)%mod;  
}  

int main() {
	int m,len,i,c=0,t,j;
	ll n;
	scanf("%d",&m);
	scanf("%s",s);
	len=strlen(s);
	p[0]=fac[0]=1;
	for (i=1;i<=100000;i++) {
		p[i]=(p[i-1]*i)%mod;fac[i]=fac[i-1]*25;
		fac[i]%=mod;
	}
	inv[100000]=fastpow(p[100000],mod-2);  
    for (i=99999;i>=0;i--) {  
        inv[i]=inv[i+1]*(i+1);  
        inv[i]%=mod;  
    }  
	for (i=1;i<=m;i++) {
		scanf("%d",&t);
		if (t==1) {
			scanf("%s",s);len=strlen(s);
		} else {
			scanf("%I64d",&n);
			v[len].push_back(n);
			d[len].push_back(++c);
			a[len]=max(a[len],n);
		}
	}
	for (i=1;i<=100000;i++) {
		if (v[i].size()) {
			mem0(dp);
			dp[i]=1;
			for (j=i+1;j<=a[i];j++) {
				dp[j]=(26*dp[j-1])%mod+(lucas(j-1,i-1)*fac[j-i])%mod;
				dp[j]%=mod;
			}
			for (j=0;j<v[i].size();j++)
				ans[d[i][j]]=dp[v[i][j]];
		}
	}
	for (i=1;i<=c;i++) printf("%I64d\n",ans[i]);
	return 0;
}
