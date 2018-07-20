#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	int n,i,cou;
	int a[200000];
	cin >> n;
	cou=0;
	for (i=1;i<=n;i++) 
	{
		cin >> a[i];
		a[i]-=cou;
		if (a[i]<0) 
		{
			cout << "NO" << endl;
			return 0;
		}
		cou=0;
		if (a[i]%2==1) cou++;
	}
	if (cou!=0) cout << "NO" << endl; else
	   cout << "YES" << endl;
	return 0;
}
