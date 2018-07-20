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
const int maxn=1005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f,mod=1e9+7;   
const ld pi=acos(-1.0L);
ll num[maxn],a[maxn],p[maxn];
char s[maxn]; 

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
//组合数公式
ll lukas(ll n,ll m){  
	if (m==0) return 1;
    if (n<m) {  
        return 0;  
    } else return p[n]*(fastpow((p[m]*p[n-m])%mod,mod-2)%mod)%mod;  
}  

int main() {
	ll i,len,k,j;
	p[0]=1;
	for (i=1;i<=1000;i++) p[i]=(p[i-1]*i)%mod;
	scanf("%s%I64d",s,&k);
	if (k==0) {
		cout << 1;return 0;
	}
	len=strlen(s);
	if (k==1) {
		cout << len-1;return 0;
	}
	if (s[0]=='1'&&len==1) {
		if (k==0) cout << 1; else cout << 0;
		return 0;
	}
	a[1]=0;
	for (i=2;i<=1000;i++) {
		int j=i,cnt=0;
		while (j) {
			if (j%2==1) cnt++;
			j/=2;
		}
		a[i]=a[cnt]+1;
	}
	ll cnt=0;
	ll ans=0;
	for (i=0;i<len;i++) {
		if (s[i]=='1') {
			for (j=0;j<=1000&&j<=len-i-1;j++) {
				if (j+cnt==0) continue;
				if (a[j+cnt]==k-1) 
					ans=(ans+lukas(len-i-1,j))%mod;
			}
			cnt++;
		}
//		cout << ans << endl;
	}
	if (a[cnt]==k-1) ans++;
	ans%=mod;
	printf("%I64d\n",ans);
	return 0;
}
