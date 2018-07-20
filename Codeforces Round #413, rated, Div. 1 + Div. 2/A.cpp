#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	int n,t,k,d;
	scanf("%d%d%d%d",&n,&t,&k,&d);
	int ans=n/k*t;
	if (n%k!=0) ans+=t;
	if (ans>d+t) cout << "YES"; else cout << "NO";
	return 0;
}
