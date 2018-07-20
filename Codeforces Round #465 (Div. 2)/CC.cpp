#include <cstdio>
#include <iostream>
#include <string.h>
#include <string> 
#include <map>
#include <queue>
#include <deque>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>
#include <iomanip>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);

db sqr(db x) {
	return x*x;
}

int main() {
	db x1,y1,r,x2,y2;
	cin >> r >> x1 >> y1 >> x2 >> y2;
	if (sqr(x2-x1)+sqr(y2-y1)>=sqr(r)) {
		printf("%.10lf %.10lf %.10lf",x1,y1,r);
	} else {
		if (x1==x2) {
			db p=y1+r,q=y1-r;
			db y,R;
			if (abs(p-y2)>abs(q-y2)) {
				y=(p+y2)/2.0;
				R=abs(p-y2)/2.0;
			} else  {
				y=(q+y2)/2.0;
				R=abs(q-y2)/2.0;
			}
			printf("%.10lf %.10lf %.10lf",(db)x1,y,R);
			return 0;
		}
		db k=(y2-y1)/(x2-x1);
		db a,b,c;
		a=sqr(k)+1;
		b=-2.0*x1-2.0*k*(y1-k*x1)-2*k*y1;
		c=sqr(x1)+sqr(y1-k*x1)-2.0*y1*(y1-k*x1)+sqr(y1)-sqr(r);
		db delta=sqr(b)-4.0*a*c;
		db X1,X2,Y1,Y2;
		X1=(sqrt(delta)-b)/2.0/a;
		X2=(-sqrt(delta)-b)/2.0/a;
		Y1=k*(X1-x1)+y1;
		Y2=k*(X2-x1)+y1;
		db X,Y,R;
		if (sqr(X1-x2)+sqr(Y1-y2)>sqr(X2-x2)+sqr(Y2-y2)) {
			X=(X1+x2)/2.0;
			Y=(Y1+y2)/2.0;
			R=sqrt(sqr(x1-x2)+sqr(y1-y2))+r;
			R/=2.0;
		} else {
			X=(X2+x2)/2.0;
			Y=(Y2+y2)/2.0;
			R=sqrt(sqr(x1-x2)+sqr(y1-y2))+r;
			R/=2.0;
		}
		printf("%.14lf %.14lf %.14lf",X,Y,R);
	}
	return 0;
}
