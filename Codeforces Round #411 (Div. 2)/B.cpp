#include <cstdio>
#include <iostream>
using namespace std;
int n,i;

int main() {
	char c[4]={'a','a','b','b'};
	scanf("%d",&n);
	for (i=0;i<n;i++) {
		cout << c[i%4];
	}
	return 0;
}
