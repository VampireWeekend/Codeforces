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
bool a[10000005];

int main() {
	ll n,k,i;
	cin >> n >> k;
	mem0(a);
	for (i=1;;i++) {
		if (a[n%i]) break;
		a[n%i]=1;
	}
	if (k>=i) cout << "No"; else cout << "Yes";
	return 0;
}
