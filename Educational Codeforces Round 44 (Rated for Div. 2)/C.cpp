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
ll a[maxn];

int main() {
	int n,m,k,i,j,d,r=0;
	scanf("%d%d%d",&n,&k,&d);
	m=n*k;
	for (i=1;i<=n*k;i++) {
		scanf("%I64d",&a[i]);
	}
	sort(a+1,a+m+1);
	for (i=1;i<m;i++) {
		if (a[i+1]-a[1]>d) r=i;
		if (r!=0) break;
	}
	if (!r) r=m;
	if (r<n) {
		printf("0");return 0;
	}
	ll ans=0;
	int rem=(m-r)/k;
	for (i=r;i>=1;i--) {
		if (i%k==1||k==1) ans+=a[i]; else {
			if (rem==0) continue;
			rem--;ans+=a[i];
		}
	}
	printf("%I64d\n",ans); 
	return 0;
}
