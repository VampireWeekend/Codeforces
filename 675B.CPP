#include <cstdio>
#include <iostream>
using namespace std;

long long max (long long a,long long b)
{
	if (a>b) return a; else return b;
}

long long min (long long a,long long b)
{
	if (a<b) return a; else return b;
}

int main () 
{
	long long i,amax,amin,b,d,f,h,n,maxi,mini;
    cin >> n;
	cin >> b;
	cin >> d;
	cin >> f;
	cin >> h;
	maxi=0;
	mini=0;
	maxi=max(maxi,d-f);
	maxi=max(maxi,b-h);
	maxi=max(maxi,b+d-f-h);
	mini=min(mini,d-f);
	mini=min(mini,b-h);
	mini=min(mini,b+d-f-h);
	amax=min(n-maxi,n);
	amin=max(1-mini,1);
	cout << (amax-amin+1)*n << endl;
	return 0;
}