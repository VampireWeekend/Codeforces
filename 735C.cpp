#include <iostream>
#include <cstdio>
using namespace std;
long long n,i,ans;
int main() 
{
	cin >> n;
	ans=0;
	i=1;
	while (i<n) {
		i=i*2;
		ans++;
	}
	cout << ans;
	return 0;
} 
