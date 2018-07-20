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
#include <bitset>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=105,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);

ll gcd(ll a,ll b) {
	ll x,y,z;
	x=a;y=b;
	if (y>x) {
		x=b;y=a;
	}
	while (y) {
		z=x;x=y;y=z%y;
	}
	return x;
}

int main() {
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		ll a,b,c;
		scanf("%I64d%I64d",&a,&b);
		if (a<b) swap(a,b);
		if (a==0||b==0) {
			if (a==0&&b==0) printf("Yes\n"); else printf("No\n");
			continue;
		}
		ll p=a*b;
		ll q=floor(exp(log((ld)p)/3.0L)+1e-5L);
		if (p==q*q*q) {
			if (a<=b*b&&a%q==0&&b%q==0) printf("Yes\n"); else printf("No\n");
		} else printf("No\n");
	}
	return 0;
}
