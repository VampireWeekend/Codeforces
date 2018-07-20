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
const int inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f,mod=1e9+7;   
const ld pi=acos(-1.0L);

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
	ll n,m,ans,k;
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	if (n==1&&m==1) {
		printf("1\n");return 0;
	} else if (k==-1&&(n+m)%2==1) {
		printf("0\n");return 0;
	}
	ans=fastpower(2,n-1);
	ans=fastpower(ans,m-1);
	ans%=mod;
	printf("%I64d",ans);
	return 0;
}

