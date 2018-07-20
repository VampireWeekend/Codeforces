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
const int maxn=10005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
ll a[maxn];

int main() {
	ll i,n,m;
	i=0;
	cin >> n;
	m=0;
	if (n>=5000) i=2000008,m=5000;
	if (n>=7500) i=4301200,m=7500;
	if (n>=7900) i=6200020,m=7900;
	if (n>=8000) i=9010000,m=8000;
	while (m<n) {
		i++;
		ll f=i,sum=0;
		while (f) {
			sum+=f%10;
			f/=10;
			if (sum>10) break;
		}
		if (sum==10) m++;
	}
	cout << i;
	return 0;
}
