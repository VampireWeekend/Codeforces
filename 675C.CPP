#include <cstdio>
#include <iostream>
#include <map>
#include <math.h>
using namespace std;

int main ()
{
	int i;
	long long n; 
	long long a[100001];
	long long sum=0;
	cin >> n;
	for (i=1;i<=n;i++) 
		cin >> a[i];
	long long ans=n;
	map <long long,long long> m;
	for (i=1;i<=n;i++)
	{
		sum+=a[i];
		m[sum]++;
	}
	sum=0;
	ans=n-m[0];
	for (i=1;i<=n;i++)
	{
		sum+=a[i];
		ans=min(ans,n-m[sum]);
	}
	cout << ans << endl;
	return 0;
}
