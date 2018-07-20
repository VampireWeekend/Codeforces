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
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
ll a[maxn];

int main() {
	ll n,x,k,i,j;
	ll ans=0;
	scanf("%I64d%I64d%I64d",&n,&x,&k);
	for (i=1;i<=n;i++)
		scanf("%I64d",&a[i]);
	sort(a+1,a+n+1);
	for (i=1;i<=n;i++) {
		ll y=a[i]/x,l,r;
		l=(y-k)*x+1;r=(y-k+1)*x;
		if (k==0) r--;
		if (k==0&&a[i]%x==0) continue;
		if (l>r||l>a[i]) continue;
		r=min(r,a[i]);
		ans+=(ll)(upper_bound(a+1,a+n+1,r)-lower_bound(a+1,a+n+1,l));
	}
	printf("%I64d\n",ans);
	return 0;
}
