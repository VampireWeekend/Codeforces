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
	ll n,mod,sum=0,k=10,i;
	scanf("%I64d%I64d",&n,&mod);
	for (i=1;i<=n;i++) {
		ll p=i,t=i; 
		while (t) {
			p=(p*10)+(t%10);
			t/=10;
		}
//		cout << p << endl;
		sum=(sum+p)%mod;
	}
	printf("%I64d\n",sum);
	return 0;
}
