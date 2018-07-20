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
	ll K,D,T;
	ld k,d,t,ans,c,rem,p;
	cin >> K >> D >> T;
	k=K;d=D;t=T;
	if (K==D) {
		ans=t;
	} else if (K<D) {
		p=(k+d)/(2.0L*t);
		c=floor((2.0L*t)/(k+d));
		ans=d*c;
		rem=1-c*p;
		if (k/t>=rem) ans+=rem*t; else ans+=k+(rem-k/t)*(2.0L*t);
	} else {
		ll R=K/D;
		if (K%D!=0) R++;
		ld r=R;
		p=(k+r*d)/(2.0L*t);
		c=floor((2.0L*t)/(k+r*d));
		ans=r*d*c;
		rem=1-c*p;
		if (k/t>=rem) ans+=rem*t; else ans+=k+(rem-k/t)*(2.0L*t);
	}
	cout << setiosflags(ios::fixed) << setprecision(15);
	cout << ans << endl;
	return 0;
}
