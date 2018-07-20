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
const int maxn=1000005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
char s[maxn];

struct qwe{
	ll ns,nh;
};
qwe a[maxn];

bool cmp(qwe x,qwe y) {
	return x.nh*y.ns<y.nh*x.ns;
}

int main() {
	ll n,i,j,ta,tb,ans=0;
	scanf("%I64d",&n);
	for (i=1;i<=n;i++) {
		scanf("%s",s);
		int len=strlen(s);
		a[i].ns=a[i].nh=0;
		ll cnt=0;
		for (j=0;j<len;j++) {
			if (s[j]=='s') a[i].ns++,cnt++; else a[i].nh++,ans+=cnt;
		}
	}
	sort(a+1,a+n+1,cmp);
	ll cnt=0;
	for (i=1;i<=n;i++) {
		ans+=cnt*a[i].nh;
		cnt+=a[i].ns;
	}
	printf("%I64d\n",ans);
	return 0;
}
