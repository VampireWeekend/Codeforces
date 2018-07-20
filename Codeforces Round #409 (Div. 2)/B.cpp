#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
string a,b,s;

int main() {
	int i;
	cin >> a;
	cin >> b;
	s="";
	for (i=0;i<a.length();i++) {
		if (b[i]<=a[i]) {
			s+=b[i];
		} else{
			cout << -1 << endl;
			return 0;
		}
	}
	cout << s << endl;
	return 0;
} 
