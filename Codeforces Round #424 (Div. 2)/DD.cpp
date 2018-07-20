#include <cstdio>
#include <iostream>
#include <vector>
#include <string.h>
#include <string> 
#include <map>
#include <algorithm>
#include <queue>
#include <math.h>
#include <cmath>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=2005,inf=0x3f3f3f3f;
int a[maxn],b[maxn];

bool check(int n,int k,int mid,int p) {
	int i,j,cnt=0,top=1;
	for (i=1;i<=n;i++) {
		for (j=top;j<=k;j++) {
			int d;
			if ((p>=b[j]&&b[j]>=a[i])||(p<=b[j]&&b[j]<=a[i]))
		        d=abs(a[i]-p);
	    	else 
		        d=abs(b[j]-p)+abs(b[j]-a[i]);
		    if (d<=mid) {
		    	cnt++;
		    	top=j+1;
		    	break;
		    }
		}
	}
	return cnt==n;
}

ll solve(int n,int k,int p) {
	ll l=0,r=2*inf;
	ll ans=2*inf,mid;
	while (l<=r) {
		mid=(l+r)/2;
		if (check(n,k,mid,p)) {
			ans=mid;
			r=mid-1;
		} else l=mid+1;
	}
	return ans;
}

int main() {
	int i,j,l,r,n,k,p;
	ll ans;
	scanf("%d%d%d",&n,&k,&p);
	for (i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	for (i=1;i<=k;i++) {
		scanf("%d",&b[i]);
	}
	sort(a+1,a+n+1);
	sort(b+1,b+k+1);
	ans=solve(n,k,p);
	printf("%I64d\n",ans);
	return 0;
}
