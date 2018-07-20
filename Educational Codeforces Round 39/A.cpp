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

int main() {
	ll n,m;
	scanf("%I64d%I64d",&n,&m);
	while (n&&m) {
		if (n>=2*m) {
			n%=2*m;
		} else if (m>=2*n) {
			m%=2*n;
		} else break;
	} 
	cout << n << ' ' << m;
	return 0;
}
