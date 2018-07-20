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
const int maxn=10005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
ll a[maxn],b[maxn];
struct aaa{
	ll x,y;
};
aaa c[maxn];

bool cmp(aaa q,aaa w) {
	return q.x<w.x;
}

int main() {
	ll n,m,i,j,ans,x,y;
	cin >> n >> m;
//	cin >> x >> y;
//	if (x<y) swap(x,y);
	for (i=1;i<=n;i++) {
		cin >> a[i];
//		if (a[i]>x) y=x,x=a[i]; else if (a[i]>y) y=a[i];
	}
	for (i=1;i<=m;i++) {
		cin >> b[i];
//		ans=max(ans,b[i]);
	}
	ans=-llinf;
	x=0;
	for (i=1;i<=n;i++) {
		for (j=1;j<=m;j++) {
			c[++x].x=a[i]*b[j];
			c[x].y=i;
		}
	}
	sort(c+1,c+x+1,cmp);
	for (i=x;i>=1;i--) {
		if (c[i].y!=c[x].y) break;
	}
	cout << c[i].x;
	return 0;
}
