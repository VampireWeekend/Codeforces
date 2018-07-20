#include <iostream>
#include <cmath>
#include <math.h>

typedef double db;

using namespace std;
const db pi=3.1415926;

db sqr(db x) {
	return x*x;
}

int main() {
	db a=0;
	db x,y;
	for (int i=1;i<=5;i++) {
		cin >> x >> y;
		a+=sqr(x/y);
	}
	a=sqrt(a);
	cout << a*1.46;
} 
