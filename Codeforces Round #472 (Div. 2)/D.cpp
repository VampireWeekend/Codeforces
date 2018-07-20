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
	ll n,i,j,cnt=1,k;
	scanf("%I64d",&n);
	ll sum=0;
	for (i=1;i<=n;i++) {
		scanf("%I64d",&a[i]);
	}
	mem0(b);
	ll last=0;
	for (i=1;i<=n-1;i++) {
		if (a[i]>cnt-1&&a[i+1]<a[i]) {
	//		ll k=i;
			b[i]=a[i]+1;
			last=i;
	/*		for (j=a[i]+1;j>=cnt+1;j--) {
				b[k--]=j;
			}
			while (k>last) b[k--]=j;
			last=i;*/
			cnt=max(cnt,a[i]+1);
		}
	}
	if (a[n]>cnt-1) {
		b[n]=a[n]+1;
		last=i;
	}
	if (last==0) {
		cout << "0";return 0;
	}
	for (i=last+1;i<=n;i++) b[i]=b[last];
	ll p=b[n];
	for (i=last-1;i>=1;i--) {
		if (b[i]<p&&b[i]) {
			if (last-i<b[last]-b[i]) continue;
			for (j=last-1,k=p-1;j>i;j--) {
				b[j]=k;
				if (k>=b[i]) k--;
			}
			p=b[i];last=i;
		}
	}
	for (j=last-1,k=p-1;j>0;j--) {
		b[j]=k;
		if (k>1&&k>a[j-1]+1) k--;
	}
	for (i=1;i<=n;i++) {
		sum+=b[i]-a[i]-1;
	}
	printf("%I64d\n",sum);
	return 0;
}
