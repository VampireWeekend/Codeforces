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
	ll a,b;
	cin >> a >> b;
	if (b-a>=10) cout << 0; else if (a==b) cout << 1; else {
		unsigned long long i,ans=1;
		for (i=a+1;i<=b;i++) {
			ans*=(i%10);
			ans%=10;
		}
		cout << ans;
	}
	return 0;
}
