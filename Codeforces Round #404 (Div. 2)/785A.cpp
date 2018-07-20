#include <iostream>
#include <cstdio> 
#include <string>
using namespace std;

int main () {
	int tot,i,n;
	string s;
	tot=0;
	cin >> n;
	for (i=1;i<=n;i++){
		cin >> s;
		if (s=="Tetrahedron") tot+=4;
		if (s=="Cube") tot+=6;
		if (s=="Octahedron") tot+=8;
		if (s=="Dodecahedron") tot+=12;
		if (s=="Icosahedron") tot+=20;
	}
	cout << tot << endl;
	return 0;
}
