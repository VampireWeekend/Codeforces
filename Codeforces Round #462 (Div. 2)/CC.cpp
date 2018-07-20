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
int a[maxn],b[maxn],c[maxn],d[maxn],p[maxn];

int main() {
	int n,i,j,l,r,ans=-1;
	while (true) {
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
	//	int cnt=0,cnt2=0,cnt3=0,cmax=0;
		for (r=l;r<=n;r++) {
			for (i=1;i<=l-1;i++) p[i]=a[i];
			for (i=l;i<=r;i++) {
				p[i]=a[r-i+l];
			}
			for (i=r+1;i<=n;i++) p[i]=a[i];
			
			for (i=1;i<=n;i++) {
		b[i]=1;
		for (j=1;j<i;j++) {
			if (p[j]<=p[i]) b[i]=max(b[i],b[j]+1);
		}
		ans=max(ans,b[i]);
		if (ans==12) {
			cout << l << ' ' << r;
			return 0;
		}
	}
	
		}
	}
	printf("%d\n",ans);
}
	return 0;
}
