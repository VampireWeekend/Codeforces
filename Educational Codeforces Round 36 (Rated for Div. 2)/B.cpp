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
const int maxn=10000,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);

int main() {
	int n,a,l,r,i,j,ans=0;
	scanf("%d%d%d%d",&n,&a,&l,&r);
	if (l==1&&r==n) {
		ans=0;
	} else if (l==1) {
		ans=abs(r-a)+1;
	} else if (r==n) {
		ans=abs(l-a)+1;
	} else {
		if (a<=l) ans=abs(r-a)+2; else
			if (a>=r) ans=abs(l-a)+2; else {
				ans=min(abs(r-a),abs(l-a))+2+r-l;
			}
	}
	cout << ans;
	return 0;
}
