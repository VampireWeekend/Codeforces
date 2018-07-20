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
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);

int main() {
	ll n,i,j,ans=0;
	scanf("%I64d",&n);
	for (i=1;i<=60;i++) {
		ans+=((n+(1ll<<(i-1ll))-1ll)/(1ll<<i))*(1ll<<(i-1ll));
//		cout << i << ' ' << ans << endl;
	}
	
	printf("%I64d\n",ans);
	return 0;
}
