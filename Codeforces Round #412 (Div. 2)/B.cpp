#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int a[107];

int main() {
	int i,x,y,p;
	scanf("%d%d%d",&p,&x,&y);
	int k=(x/50)%475;
	for (i=1;i<=25;i++) {
		k*=96;
		k+=42;
		k%=475;
		a[i]=26+k;
		if (a[i]==p) {
			cout << 0;
			return 0;
		}
	}
	int s=x;
	while (s-50>=y) {
		s-=50;
		k=(s/50)%475;
	for (i=1;i<=25;i++) {
		k*=96;
		k+=42;
		k%=475;
		a[i]=26+k;
		if (a[i]==p) {
			cout << 0;
			return 0;
		}
	}
	}
	int t=0;
	s=x;
	while (1) {
		t++;
		s+=50;
		k=(s/50)%475;
	for (i=1;i<=25;i++) {
		k*=96;
		k+=42;
		k%=475;
		a[i]=26+k;
		if (a[i]==p) {
			cout << (t+1)/2;
			return 0;
		}
	}
	}
	return 0;
}
