#include <cstdio>
#include <iostream>
#include <string.h>
#include <string> 
#include <map>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=200005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f,mod=1e9+7;   
const ld pi=acos(-1.0L);  
ll a[maxn],inv[maxn];

ll fastpow(ll base,ll index) {
	ll sum=base,an=1;
	ll i=index;
    while (i) {
    	if (i%2) an=(an*sum)%mod;
    	sum*=sum;
    	sum=sum%mod;
    	i/=2;
    }
    return an;
}

int main() {
	int n,i,j;
	ll ans=0,fac=1,g;
	scanf("%d",&n);
	for (i=1;i<=n;i++) 
		scanf("%I64d",&a[i]);
	if (n%2==0) g=(n-2)/2; else g=(n-n%4)/2;
	for (i=1;i<=g;i++) fac=(fac*((ll)i))%mod;
	inv[g]=fastpow(fac,mod-2);
	for (i=g-1;i>=0;i--) {
		inv[i]=inv[i+1]*(i+1);
		inv[i]%=mod;
	}
	if (n%2==0) {
		ll t=1;
		for (i=1;i<=n;i++) {
			if (i%2==0&&n%4==0) ans-=t*a[i]; else ans+=t*a[i];
			ans%=mod;
			if (ans<0) ans+=mod;
			if (i%2==0) {
				t=(((fac*inv[i/2])%mod)*inv[g-i/2])%mod;
			}
		}
	} else if (n%4==1) {
		ll t=1;
		for (i=1;i<=n;i++) {
			if (i%2!=0) {
				ans+=t*a[i];ans%=mod;
			} else {
				t=(((fac*inv[i/2])%mod)*inv[g-i/2])%mod;
			}
		}
	} else if (n%4==3) {
		ll t=1,last=0;
		for (i=1;i<=n;i++) {
			if (i%2==0) ans+=2*t*a[i]; else ans+=(t-last)*a[i];
			ans%=mod;
			if (ans<0) ans+=mod;
			if (i%2==0) {
				last=t;
				t=(((fac*inv[i/2])%mod)*inv[g-i/2])%mod;
			}
		}
	}
	printf("%I64d\n",ans);
	return 0;
}

