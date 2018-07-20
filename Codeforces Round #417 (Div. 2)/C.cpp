#include <cstdio>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=100005;
ll a[maxn],b[maxn];
int n;

ll check(int k) {
	int i;
	for (i=1;i<=n;i++) {
		b[i]=a[i]+(ll)k*(ll)i;
	}
	sort(b+1,b+n+1);
	ll sum=0;
	for (i=1;i<=k;i++) sum+=b[i];
	return sum;
}

int main () {
	int i,k,t,top,flag=0;
	ll s;
	cin >> n >> s;
	for (i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		if (a[i]+i<=s) flag=1;
	}
	if (!flag) {
		cout << "0 0" << endl;
		return 0;
	}
	int l,r,mid;
	l=1;r=n;
	while (l+1<r) {
		mid=(l+r)/2;
		if (check(mid)<=s) l=mid; else r=mid;
	}
	ll c;
	if ((c=check(r))<=s) cout << r; else cout << l,c=check(l);
	cout << ' ' << c << endl;
	return 0;
}
