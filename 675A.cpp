#include <cstdio>
#include <iostream>
using namespace std;
int main ()
{
	int a,b,c;
	cin >> a;
	cin >> b;
	cin >> c;
	if (c==0) 
	{
		if (a==b) cout << "YES" << endl;  else cout << "NO" << endl;
	} 
	if (c<0)
	{
		if ((b<=a)&&((a-b)%c==0)) cout << "YES" << endl;  else cout << "NO" << endl;
	}
	if (c>0)
	{
		if ( (a<=b) && ( (b-a)%c==0) ) cout << "YES" << endl;  else cout << "NO" << endl;
	}
	return 0;
}