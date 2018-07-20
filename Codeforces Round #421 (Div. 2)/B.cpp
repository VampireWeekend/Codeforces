#include <cstdio>
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <math.h>
#include <cmath>
typedef long double db;
using namespace std;
const db pi=3.1415926535898L;
const int maxn=100005;

db leng(db r,db angle) {
	return r*sin(angle);
}

db sqr(db x) {
	return x*x;
}

db solve(int a,int b,int c,int n) {
	db x,y,z;
	db r=1e6L;
	db angle=pi*(db)(b-a)/(db)n;
	x=leng(r,angle);
	angle=pi*(db)(n+a-c)/(db)n;
	y=leng(r,angle);
	angle=pi*(db)(c-b)/(db)n;
	z=leng(r,angle);
	return acos((sqr(x)+sqr(z)-sqr(y))/(2.0L*x*z))*180L;
}

int main() {
	int n,a,b,c,i,j,aa,bb,cc,mid;
	db k,ans;
	cin >> n >> k;
	k*=pi;
	a=1;ans=1e10;
	for (i=2;i<=n/2+1;i++) {
		b=i;
		int l=i+1,r=n;
		while (l<=r) {
			mid=(l+r)/2;
			db angle=solve(a,b,mid,n);
 			if (abs(angle-k)<abs(ans-k)) {
				ans=angle;
				aa=a;bb=b;cc=mid;
			}
			if (angle<k) r=mid-1; else l=mid+1;
		}
	}
	printf("%d %d %d",aa,bb,cc);
}
