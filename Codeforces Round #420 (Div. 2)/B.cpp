#include <cstdio>
#include <iostream>
#include <string.h> 
using namespace std;
const int maxn=55;
typedef long long ll;

int main() {
	ll m,b,ans=0;
	int i,j;
	cin >> m >> b; 
	for (i=0;i<=b;i++) {
		ll x,y;
		y=(ll)i;
		x=m*(b-y);
		ans=max(ans,y*(y+1)/2*(x+1)+x*(x+1)/2*(y+1));
	}
	cout << ans;
	return 0;
} 
