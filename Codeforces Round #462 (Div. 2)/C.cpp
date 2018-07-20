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
const int maxn=2005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int a[maxn],b[maxn],c[maxn],d[maxn];
int dp1[maxn],dp2[maxn];

int main() {
	int n,i,j,l,r,ans=-1;
	scanf("%d",&n);
	c[0]=0;
	for (i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		b[i]=1;
		for (j=1;j<i;j++) {
			if (a[j]<=a[i]) b[i]=max(b[i],b[j]+1);
		}
		ans=max(ans,b[i]);
		if (a[i]==1) c[i]=c[i-1]+1; else c[i]=c[i-1];
	}
	d[n+1]=0; 
	for (i=n;i>=1;i--) {
		if (a[i]==2) d[i]=d[i+1]+1; else d[i]=d[i+1];
	}
	for (l=1;l<=n;l++) {
		int cnt=0,cnt2=0,cnt3=0,cmax=0;
		dp1[l-1]=dp2[l-1]=0;
		for (r=l;r<=n;r++) {
			if (a[r]==2) {
				ans=max(ans,d[r]+dp1[r-1]+c[l-1]);
				ans=max(ans,d[r]+dp2[r-1]+c[l-1]);
			}
	//		if (a[r]==2) cnt++,cnt3=0; else cnt2++,cnt3++;
	//		cmax=max(cmax,cnt+cnt3);
			if (a[r]==1) dp1[r]=max(dp1[r-1]+1,dp2[r-1]+1);
				else dp1[r]=dp1[r-1];
			if (a[r]==2) dp2[r]=dp2[r-1]+1;
				else dp2[r]=dp2[r-1];
		}
		ans=max(ans,d[r]+dp1[r-1]+c[l-1]);
		ans=max(ans,d[r]+dp2[r-1]+c[l-1]);
	}
	printf("%d\n",ans);
	return 0;
}
