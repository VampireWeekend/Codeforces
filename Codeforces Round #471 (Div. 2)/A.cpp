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
	ll h,m,d,c,n; 
	ll hh,mm;
	cin >> hh >> mm;
	db a1,a2;
	cin >> h >> d >> c >> n;
	ll cnt=h/n;
	if (h%n!=0) cnt++;
	a1=cnt*c;
	cout << setiosflags(ios::fixed) << setprecision(10);
	if (hh>=20) cout << a1*0.8 << endl; else {
		ll t=(20-hh-1)*60+(60-mm);
		h+=d*t;
		cnt=h/n;
		if (h%n!=0) cnt++;
		a2=cnt*c*0.8;
		db ans=min(a1,a2);
		cout << ans;
	}
	return 0;
}
