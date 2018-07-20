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
typedef double db;
const int maxn=3005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
db ans[maxn],cy[maxn];
int cx[maxn];

int sqr(int x) {
	return x*x;
}

int main() {
	int n,i,j,r,x;
	db my,del;
	scanf("%d%d",&n,&r);
	for (i=1;i<=n;i++) {
		scanf("%d",&x);
		cx[i]=x;
		my=-10000;
		for (j=1;j<i;j++) {
			if (abs(cx[j]-x)>2*r) continue;
			if (abs(cx[j]-x)==2*r) {
				if (my<cy[j]) my=max(my,cy[j]),del=my;
				continue;
			}
			db y2=sqrt((db)(sqr(2*r)-sqr(cx[j]-x)));
			if (my<y2+cy[j]) {
				my=max(my,y2+cy[j]);
				del=y2+cy[j];
			}
		}
		if (abs(my+10000)<1e-6) {
			cy[i]=r;continue;
		}
		cy[i]=del;
	}
	for (i=1;i<=n;i++) printf("%.8lf ",cy[i]);
	return 0;
}
