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
const int maxn=100005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);  

int main() {
	ll l,r,x,y,k,i;
	cin >> l >> r >> x >> y >> k;
	for (i=x;i<=y;i++) {
		if (i*k>=l&&i*k<=r) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}

