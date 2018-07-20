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
	ll n,i,ans,q,x;
	scanf("%I64d%I64d",&n,&q);
	for (i=1;i<=q;i++) {
		scanf("%I64d",&x);
		ll nq=n;
		ans=0;
		while (nq>0) {
			if (x%2==1) {
				ans+=(x+1)/2;
				break;
			}
			ans+=(nq+1)/2;
			if (nq%2==0) {
				x/=2;
			} else {
				if (x==2) {
					x=nq/2;
				} else {
					x=x/2-1;
				}
			}
			nq/=2;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
