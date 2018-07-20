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
#define pb push_back 
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=100005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
ll a[maxn],b[maxn],x[maxn],y[maxn];
map<int,ll> mp;

int main() {
	int n,m,i,j;
	ll ans=0;
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		scanf("%I64d%I64d",&a[i],&x[i]);
		mp[a[i]]=x[i];
		ans+=x[i];
	}
	scanf("%d",&m);
	for (i=1;i<=m;i++) {
		scanf("%I64d%I64d",&b[i],&y[i]);
		if (mp[b[i]]<y[i]) {
			ans+=y[i]-mp[b[i]];
			mp[b[i]]=y[i];
		}
	}
	printf("%I64d\n",ans);
	return 0;
}
