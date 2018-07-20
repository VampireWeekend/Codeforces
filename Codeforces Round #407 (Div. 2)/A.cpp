#include <cstdio>
#include <iostream>
using namespace std;
int n,i,k,c;

int main () {
    cin >> n >> k;
    int ans=0;
	for (i=1;i<=n;i++) {
		cin >> c;
		ans+=c/k+1;
		if (c%k==0) ans--;
	}
	if (ans%2==0) cout << ans/2 << endl; else cout << ans/2+1 << endl;
	return 0;	
}
