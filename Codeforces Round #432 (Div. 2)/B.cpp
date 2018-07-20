#include <cstdio>
#include <iostream>
#include <string.h>
#include <string> 
#include <map>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);

ll sqr(ll x) {
	return x*x;
}

int main() {
	ll xa,xb,xc,ya,yb,yc;
	cin >> xa >> ya >> xb >> yb >> xc >> yc;
	if ((ya-yb)*(xb-xc)==(yb-yc)*(xa-xb)) {
		cout << "No";
		return 0;
	}
	if (sqr(xb-xa)+sqr(yb-ya)==sqr(xc-xb)+sqr(yc-yb)) cout << "Yes"; else cout << "No";
	return 0;
}

