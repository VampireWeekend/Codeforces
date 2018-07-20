#include <cstdio>
#include <iostream>
#include <string>
#include <math.h>
#include <cmath>
using namespace std;

int main () 
{
	string s;
	int i,len,ans;
	cin >> s;
	len = s.length();
	ans=min(abs(s[0]-'a'),26-abs('a'-s[0]));
	for (i=1;i<=len-1;i++)
	{
		ans+=min(abs((int)s[i]-(int)s[i-1]),26-abs((int)s[i]-(int)s[i-1]));
	}
	cout << ans << endl;
	return 0;
}
