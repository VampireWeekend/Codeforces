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
	int l,r,a,ans;
	cin >> l >> r >> a;
	ans=min(l,r)*2;
	r-=ans/2;l-=ans/2;
	if (l>0) {
		int q=min(l,a);
		ans+=q*2;
		a-=q;l-=q;
	} else {
		int q=min(r,a);
		ans+=q*2;
		a-=q;r-=q;
	}
	if (a>0) {
		ans+=a/2*2;
	}
	cout << ans;
	return 0;
}
