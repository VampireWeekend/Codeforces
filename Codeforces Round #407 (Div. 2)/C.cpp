#include <cstdio>
#include <iostream>
#include <cmath>
typedef long long LL;
using namespace std;
LL a[100001];
LL b[100001],c[100001];

LL max(LL a,LL b) {
	if (a>b) return a; else return b;
}

int main () {
	int n,i;
	cin >> n;
	cin >> a[0];
    for (i=1;i<n;i++) {
		cin >> a[i];
		b[i]=abs(a[i]-a[i-1]);
		if (i%2==0) b[i]=-b[i];
		c[i]=-b[i];
	}
	LL last=0,ans=0;
	for (i=1;i<n;i++){
		last = max(0,last)+b[i];
        ans = max(ans,last);
	}
    LL s=ans;
    last=0;ans=0;
	for (i=1;i<n;i++) {
		last = max(0,last)+c[i];
        ans = max(ans,last);
	}
    s=max(s,ans);
    cout << s;
	return 0;
}
