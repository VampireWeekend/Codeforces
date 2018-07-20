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
const int maxn=200005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int a[maxn];

int main() {
	int n,i,j;
	scanf("%d",&n);
	j=-1;
	for (i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		if (i!=1) j=max(j,abs(a[i]-a[i-1]));
		if (a[i]==a[i-1]&&i!=1) {
			printf("NO\n");
			return 0;
		}
	}
	if (j==1) {
		int ans=-1;
		for (i=1;i<=n;i++) ans=max(ans,a[i]);
		printf("YES\n%d 1\n",ans);return 0;
	}
	if (n==1) {
		printf("YES\n%d 1\n",a[1]);return 0;
	}
	for (i=2;i<=n;i++) {
		if (abs(a[i]-a[i-1])!=j&&abs(a[i]-a[i-1])!=1) {
			printf("NO\n");
			return 0;
		}
	}
	for (i=2;i<=n;i++) {
		if (abs(a[i]-a[i-1])==1) {
			if (a[i]%j==0&&a[i-1]%j==1&&a[i]/j==a[i-1]/j) {
				printf("NO\n");
				return 0;
			}
			if (a[i]%j==1&&a[i-1]%j==0&&a[i]/j==a[i-1]/j) {
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n1000000000 %d\n",j);
	return 0;
}
