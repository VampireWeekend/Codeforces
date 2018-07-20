#include <cstdio>
#include <iostream>
using namespace std;
int main () {
	long long n,m,k,ans,l,r,mid,lv,rv;
	cin >> n >> m;
	ans=m;
	k=n-m;
	if (n-m<=0) {
		cout << n << endl;
		return 0;
	}
	l=1;r=2e9;
	lv=1;rv=(r+1)*r/2;
	while (l<r-1) {
		mid=(l+r)/2;
		long long value=(1+mid)*mid/2;
		if (value>k) {
			r=mid;
			rv=value;
		}
		if (value<k) {
			l=mid;
			lv=value;
		}
		if (value==k) {
			cout << mid+m << endl;
			return 0;
		}
	}
	if (lv>=k) cout << l+m << endl; else cout << r+m << endl; 
}
