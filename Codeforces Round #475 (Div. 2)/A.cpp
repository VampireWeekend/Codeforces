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
ll t[maxn];

int main() {
	ll n,a,b,c,T,i,j;
	cin >> n >> a >> b >> c >> T;
	ll ans=0;
	for (i=1;i<=n;i++) {
		scanf("%I64d",&t[i]);
		if (c>b) ans+=(T-t[i])*(c-b)+a; else ans+=a; 
	}
	cout << ans << endl;
	return 0;
}
