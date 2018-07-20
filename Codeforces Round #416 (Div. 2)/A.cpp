#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;

int main() {
	int a,b,i=0;
	cin >> a >> b; 
	while ((a-i-1>=0&&i%2==0)||(b-i-1>=0&&i%2==1)) {
		i++;
		if (i%2) a-=i; else b-=i;
	}
	if (i%2==0) cout << "Vladik";
	 else cout << "Valera";
	return 0;
}
