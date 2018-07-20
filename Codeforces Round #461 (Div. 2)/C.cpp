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
bool a[100005];

int main() {
	ll n,k,i;
//	cin >> n >> k;
//	if (k>=n) cout << "No";

	for (ll n=1;n<=100000000;n++) {
		mem0(a);
		for (i=1;i<=n;i++) {
			if (a[n%i]) break; else a[n%i]=1;
		}
		if (i>=23) cout << n << endl;
//		cout << n  << " " << i << endl;
	}
	return 0;
}
