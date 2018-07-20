#include <cstdio>
#include <iostream>
#include <math.h>
using namespace std;
const int maxn=100005;

int main() {
	double a,n,h,sum,ans;
	int i;
	scanf("%lf%lf",&n,&h);
	sum=h*h;
	for (i=1;i<n;i++) {
		double p=(double)i/n;
		ans=sqrt(sum*p);
		printf("%.10lf ",ans);
	}
	return 0;
}
