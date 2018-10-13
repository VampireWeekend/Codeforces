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
#include <assert.h>
#define pb push_back 
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef pair<int,int> pp;
const int maxn=200005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
int a[maxn];

int main() {
	int n,x;
	scanf("%d%d",&n,&x);
	for (int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	int l,r;
	l=lower_bound(a+1,a+n+1,x)-a;
	r=upper_bound(a+1,a+n+1,x)-a;
	int m=(n+1)/2;ll ans=0;
	if (x<=a[1]) {
		for (int i=1;i<=m;i++) {
			ans+=(ll)abs(a[i]-x);
		}
		printf("%I64d\n",ans);
		return 0;
	}
	if (x>=a[n]) {
		for (int i=m;i<=n;i++) {
			ans+=(ll)abs(a[i]-x);
		}
		printf("%I64d\n",ans);
		return 0;
	}
if (a[l]==x) {
	if (m<=l) {
		for (int i=m;i<l;i++) {
			ans+=(ll)abs(a[i]-x);
		}
	} else {
		r--;
		for (int i=r+1;i<=m;i++) {
			ans+=(ll)abs(a[i]-x);
		}
	}
} else {
	if (m<=l) {
		for (int i=m;i<=l;i++) {
			ans+=(ll)abs(a[i]-x);
		}
	} else {
		for (int i=l;i<=m;i++) {
			ans+=(ll)abs(a[i]-x);
		}
	}
}
	printf("%I64d\n",ans);
	return 0;
}
