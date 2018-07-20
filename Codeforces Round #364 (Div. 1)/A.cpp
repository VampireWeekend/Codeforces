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
	int n,k;
	db T,v1,v2,l,ans,j;
	cin >> n >> l >> v1 >> v2 >> k;
	int s=n/k;
	if (n%k!=0) s++;
	ans=l*(2.0*(db)s+v1/v2-l)/(v2+v1*2.0*(db)s-v1);
	printf("%.10lf\n",ans);
	return 0;
}
