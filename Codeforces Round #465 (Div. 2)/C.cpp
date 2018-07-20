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
typedef long double db;
const int inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   

db sqr(db x) {
	return x*x;
}

int main() {
	db x1,y1,r,x2,y2;
	cin >> r >> x1 >> y1 >> x2 >> y2;
	cout << setiosflags(ios::fixed) << setprecision(12);
	if (((ll)(x2-x1)*(ll)(x2-x1))+((ll)(y2-y1)*(ll)(y2-y1))>=(ll)(r)*(ll)(r)) {
		cout << x1 << ' ' << y1 << ' ' << r;
	} else {
		if (x1==x2) {
			db p=y1+r,q=y1-r;
			db y,R;
			if (abs(p-y2)>abs(q-y2)) {
				y=(p+y2)/2.0L;
				R=abs(p-y2)/2.0L;
			} else  {
				y=(q+y2)/2.0L;
				R=abs(q-y2)/2.0L;
			}
			cout << x1 << ' ' << y << ' ' << R;
			return 0;
		}
		db k=(y2-y1)/(x2-x1);
		db a,b,c;
		a=sqr(k)+1.0L;
		b=-2.0L*x1-2.0L*k*(y1-k*x1)-2.0L*k*y1;
		c=sqr(x1)+sqr(y1-k*x1)-2.0L*y1*(y1-k*x1)+sqr(y1)-sqr(r);
		db delta=sqr(b)-4.0L*a*c;
		db X1,X2,Y1,Y2;
		X1=(sqrtl(delta)-b)/2.0L/a;
		X2=(-sqrtl(delta)-b)/2.0L/a;
		Y1=k*(X1-x1)+y1;
		Y2=k*(X2-x1)+y1;
		db X,Y,R;
		if (sqr(X1-x2)+sqr(Y1-y2)>sqr(X2-x2)+sqr(Y2-y2)) {
			X=(X1+x2)/2.0L;
			Y=(Y1+y2)/2.0L;
			R=sqrtl(sqr(X-x2)+sqr(Y-y2));
		} else {
			X=(X2+x2)/2.0L;
			Y=(Y2+y2)/2.0L;
			R=sqrtl(sqr(X-x2)+sqr(Y-y2));
		}
		cout << X << ' ' << Y << ' ' << R;
	}
	return 0;
}
