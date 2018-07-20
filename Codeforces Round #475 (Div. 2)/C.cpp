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
const ll llinf=0x3f3f3f3f3f3f3f3f,mod=1e9+9;   
const ld pi=acos(-1.0L);
char s[maxn];

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
	ll n,A,B,k,i,j,sum=0;
	scanf("%I64d%I64d%I64d%I64d",&n,&A,&B,&k);
	scanf("%s",s);
	ll t=(n+1)/k;
	if (A==1&&B==1) {
		for (i=0;i<k;i++) {
			if (s[i]=='+') sum++; else sum--;
		}
		sum=(sum*t)%mod;
		printf("%I64d\n",sum);
		return 0;
	}
	for (i=0;i<k;i++) {
		ll a1=fastpower(A,n-i)*fastpower(B,i);
		a1%=mod;
		ll p;
		if (s[i]=='+') p=1; else p=-1;
		if (t==1) {
			sum+=a1*p;
			sum%=mod;
			continue;
		}
		ll q=fastpower(A,(t-1)*k)*fastpower(B,k);
		q=((q%mod)-1+mod)%mod;
		q=fastpower(q,mod-2);
		ll w=fastpower(B,t*k);
		w=(w+mod-1)%mod;
		sum+=((((a1*q)%mod)*w)%mod)*p;
		sum%=mod;
	}
	sum=(sum+mod)%mod;
	printf("%I64d",sum);
	return 0;
}
