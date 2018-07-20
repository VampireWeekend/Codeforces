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
#include <iomanip>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=20005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
ll a,b,f,k;
ll t[maxn];

int main() {
	cin >> a >> b >> f >> k;
	ll l,r,mid,p=-1,e;
	int i;
	l=1;r=1e9;
	while (l<=r) {
		mid=(l+r)/2;
		if (mid%2==1) {
			if ((mid-1)*a+f<=b) p=mid,l=mid+1; else r=mid-1;
		} else {
			if (mid*a-f<=b) p=mid,l=mid+1; else r=mid-1;
		}
	}
	if (b>=a*k) {
		cout << 0;
		return 0; 
	}
	if (b<f||b<a-f||(b<2*(a-f)&&k>=2)||(b<2*f&&k>=3)) {
		cout << -1;
		return 0; 
	}
	l=1;r=1e9;e=0;
	while (l<=r) {
		mid=(l+r)/2;
		if (mid*a*2<=b) e=mid,l=mid+1; else r=mid-1;
	}
	t[1]=p;
	if (t[1]>=k) {
		cout << 1; return 0;
	}
	if (t[1]%2==1) {
		if ((k-t[1])*a+a-f<=b) {
			cout << 1; return 0;
		}
	} else {
		if ((k-t[1])*a+f<=b) {
			cout << 1; return 0;
		}
	}
	for (i=2;i<=k;i++) {
		if (t[i-1]%2==1) {
			if (e*a*2+2*(a-f)<=b) t[i]=t[i-1]+e*2+1; else t[i]=t[i-1]+e*2;
		} else {
			if (e*a*2+2*f<=b) t[i]=t[i-1]+e*2+1; else t[i]=t[i-1]+e*2;
		}
		if (t[i]>=k) {
			cout << i;return 0;
		}
		if (t[i]%2==1) {
			if ((k-t[i])*a+a-f<=b) {
				cout << i; return 0;
			}
		} else {
			if ((k-t[i])*a+f<=b) {
				cout << i; return 0;
			}
		}
	}
	cout << -1;
	return 0;
}
