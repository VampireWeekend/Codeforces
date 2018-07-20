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
const int maxn=500005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int a[maxn],dp[maxn];

int main() {
	int n,k,d,i,j;
	scanf("%d%d%d",&n,&k,&d);
	for (i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	dp[0]=1;
	int l=0,cnt=0;
	for (i=k;i<=n;i++) {
		if (dp[i-k]) cnt++;
		while (a[i]-a[l+1]>d&&i-l+1>k) {
			if (dp[l]) cnt--;
			l++;
		}
		if (cnt&&a[i]-a[l+1]<=d&&i-l+1>k) dp[i]=1;
	}
	if (dp[n]) printf("YES"); else printf("NO");
	return 0;
}
