#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
typedef long long ll;
const int maxn=10005;

int main() {
	int n,i,a,b;
	cin >> a >> b;
	n=min(a,b);
	ll sum=1;
	for (i=1;i<=n;i++) {
		sum*=(ll)i;
	}
	cout << sum;
	return 0;
}
