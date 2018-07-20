#include <cstdio>
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int c,v0,v1,a,l,t,sum;
	cin >> c >> v0 >> v1 >> a >> l;
	sum=v0;t=1;
	while (sum<c) {
		t++;
		if (v0<v1) v0+=a;
		if (v0>v1) v0=v1;
		sum+=v0-l;
	}
	cout << t;
	return 0;
}
