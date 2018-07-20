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
const int maxn=500005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
ll sum[maxn],a[maxn],t[maxn];

bool check(ll mid,ll q,ll p,ll n) {
	ll i,j,k=p,ssum=0;
	mem0(t);
	for (i=1;i<=n;i++) {
		ssum+=sum[i]+t[i];
		if (ssum>=mid) continue;
		ll com=mid-ssum;
		k-=com;
		if (k<0) return false;
		ssum+=com;
		t[min(n+1,i+q*2+1)]-=com;
	}
	return true;
}

int main() {
	ll n,k,r,i,j,l,mid,q;
	scanf("%I64d%I64d%I64d",&n,&q,&k);
	mem0(sum);
	for (i=1;i<=n;i++) {
		scanf("%I64d",&a[i]);
		sum[max(1ll,i-q)]+=a[i];
		sum[min(n+1,i+q+1)]-=a[i];
	}
	l=1;r=2e18;ll ans=0;
	while (l<=r) {
		mid=(l+r)/2;
		if (check(mid,q,k,n)) ans=mid,l=mid+1; else r=mid-1;
	} 
	printf("%I64d\n",ans);
	return 0;
}
