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
ll a[maxn],dp[maxn];

ll fastpower(ll base,ll index) {
	ll ans,now;
	if (index<0) return 1;
	ans=1;
	now=base;
	ll k=index;
	while (k) {
		if (k%2) ans=ans*now;
		ans%=mod;
		now=now*now;
		now%=mod;
		k/=2;
	}
	return ans;
}

int main() {
	ll x,y,i,j,n=0;
	cin >> x >> y;
	if (y%x!=0) {
		cout << 0;return 0;
	}
	for (i=1;i*i<=y;i++) {
		if (i%x==0&&y%i==0) a[++n]=i;
		if (i*i!=y&&y%(y/i)==0&&(y/i)%x==0) a[++n]=y/i;
	}
	sort(a+1,a+n+1);
	for (i=n;i>=1;i--) {
		dp[i]=fastpower(2,y/a[i]-1);
		for (j=i+1;j<=n;j++) {
			if (a[j]%a[i]==0) dp[i]-=dp[j];
			dp[i]=(dp[i]+mod)%mod;
		}
	}
	cout << dp[1];
	return 0;
}
