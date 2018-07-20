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
	ll x,y,i,last=-1,j;
	scanf("%I64d%I64d",&x,&y);
	for (i=y;i>x;i--) {
		int flag=0;
		for (j=2;j*j<=i&&j<=x;j++) {
			if (i%j==0) {
				flag=1;break;
			}
		}
		if (!flag) {
			last=i;break;
		}
	}
	printf("%I64d\n",last);
	return 0;
}
