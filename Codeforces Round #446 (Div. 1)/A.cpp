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
ll a[maxn]; 

ll gcd(ll x,ll y) {
	if (x<y) swap(x,y);
	ll z;
	while (y) {
		z=x%y;
		x=y;
		y=z;
	}
	return x;
}

int main() {
	int n,i,j=0;
	ll p;
	scanf("%d",&n);
	scanf("%lld",&a[1]);p=a[1];
	for (i=2;i<=n;i++) {
		scanf("%lld",&a[i]);
		ll o=gcd(p,a[i]);
		if (o!=p) j++;
		p=o;
	}
	if (p!=1) {
		printf("-1\n");return 0;
	}
	int cnt=0;
	for (i=1;i<=n;i++) {
		if (a[i]==1) cnt++;
	}
	if (cnt!=0) printf("%d\n",n-cnt); else {
		int mn=inf;
		for (i=1;i<=n;i++) {
			p=a[i];cnt=0;
			for (j=i+1;j<=n;j++) {
				p=gcd(p,a[j]);
				cnt++;
				if (p==1) break;
			}
			if (p==1) mn=min(mn,cnt);
		}
		printf("%d\n",n+mn-1);
	}
	return 0;
}
