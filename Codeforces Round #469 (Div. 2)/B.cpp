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
ll a[maxn],b[maxn];

int main() {
	int n,m,i,j;
	ll sa,sb,sq;
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++) {
		scanf("%I64d",&a[i]);
	}
	int ans=0;
	sb=0;
	sa=a[1];sq=1;
	for (i=1;i<=m;i++) {
		scanf("%I64d",&b[i]);
		sb+=b[i];
		while (sa<sb&&sq<n) {
			sq++;
			sa+=a[sq];
		}
		if (sa==sb) {
			ans++;
			sb=0;sq++;sa=a[sq];
		}
	}
	printf("%d\n",ans);
	return 0;
}
