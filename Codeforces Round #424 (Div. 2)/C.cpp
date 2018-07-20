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
const int maxn=2005;
int n,k;
int a[maxn],b[maxn],sum[maxn];
bool f[8000005];

int main() {
	int i,j;
	scanf("%d%d",&k,&n);
	sum[0]=0;
	mem0(f);
	for (i=1;i<=k;i++) {
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
		f[sum[i]+4000000]=1;
	}
	for (i=1;i<=n;i++) {
		scanf("%d",&b[i]);
	}
	int ans=0;
	sort(sum+1,sum+k+1);
	for (i=1;i<=k;i++) {
		if (sum[i]==sum[i-1]&&i!=1) continue;
		int flag=1;
		for (j=1;j<=n;j++) {
			int d=b[j]-b[1]+sum[i]+4000000; 
			if (d<=8000000&&d>=0)
			  if (f[d]) continue;
				flag=0;
			    break;
		}
		if (flag) ans++;
	}
	printf("%d\n",ans);
	return 0;
}
