#include <cstdio>
#include <iostream>
#include <string.h>
#include <string> 
#include <map>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=7000005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
ll a[105],b[maxn];

int main() {
	int n,i,j,m=0;
	ll k,s,ans=1;
	scanf("%d%I64d",&n,&k);
	s=k;
	for (i=1;i<=n;i++) {
		scanf("%I64d",&a[i]);
		s+=a[i];
		for (j=1;j<=sqrt(a[i]);j++) {
			b[m++]=j;
			if (j*j!=a[i]) b[m++]=(a[i]+j-1)/j;
		}
	}
	sort(b,b+m);
	m=unique(b,b+m)-b;
	b[m]=llinf;
	for (i=0;i<m;i++) {
		ll sum=0,d;
		for (j=1;j<=n;j++) 
			sum+=(a[j]+b[i]-1)/b[i]; 
		d=s/sum;
		if (d>=b[i]&&d<b[i+1]) ans=max(ans,d);
	}
	printf("%I64d\n",ans);
	return 0;
}

