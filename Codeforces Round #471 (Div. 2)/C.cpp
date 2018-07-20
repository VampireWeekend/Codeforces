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
const int maxn=1000005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f,lim=1e18;   
const ld pi=acos(-1.0L);
vector<ll> v,a;

ll sqr(ll x) {
	return x*x;
}

ll add(ll l,ll r) {
	ll la,ra,mid,al,ar;
	la=2;ra=pow(lim,0.5)+1000;al=-1;
	while (la<=ra) {
		mid=(la+ra)/2;
		if (sqr(mid)>=l) al=mid,ra=mid-1; else la=mid+1;
	}
	la=2;ra=pow(lim,0.5)+1000;ar=-1;
	while (la<=ra) {
		mid=(la+ra)/2;
		if (sqr(mid)>r) ar=mid,ra=mid-1; else la=mid+1;
	}
	return ar-al;
}

bool check(ll i) {
	ll p=sqrt(i);
	if (sqr(p)==i) return true;
	if (sqr(p+1)==i) return true;
	if (sqr(p-1)==i) return true;
	return false;
}

int main() {
	int q,i,j,k;
	ll l,r;
	scanf("%d",&q);
	for (i=2;i<=1e6;i++) {
		int flag=0;
		ll p=i;
		for (j=2;j<=64;j++) {
			if (lim/p<i) break;
			p*=i;
			if (j!=2) a.push_back(p);
		}
	}
	sort(a.begin(),a.end());
	a.erase(unique(a.begin(),a.end()),a.end());
	int size=a.size();
	for (i=0;i<size;i++) {
		if (!check(a[i])) v.push_back(a[i]);
	}
	for (i=1;i<=q;i++) {
		scanf("%I64d%I64d",&l,&r);
		ll ans=0;
		if (l<=1) ans++;
		ans+=upper_bound(v.begin(),v.end(),r)-lower_bound(v.begin(),v.end(),l);
		ans+=add(l,r);
		printf("%I64d\n",ans);
	}
	return 0;
}
