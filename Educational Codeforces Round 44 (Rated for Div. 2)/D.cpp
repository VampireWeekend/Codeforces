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
	ll n,h,m,l,r,mid;
	scanf("%I64d%I64d",&n,&h);
	l=1,r=2e9;m=-1;
	while (l<=r) {
		mid=(l+r)/2;
		if (mid*(mid+1)/2>=n) m=mid,r=mid-1; else l=mid+1; 
	}
	if (h>=m) {
		printf("%I64d\n",m);
		return 0;
	}
	ll ans=(n-h*(h+1)/2+h-1)/h+h;
	printf("%I64d\n",ans);
	return 0;
}
