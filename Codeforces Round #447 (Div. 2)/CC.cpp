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
const int maxn=5005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int a[maxn];
bool f[1000005];

ll gcd(ll x,ll y) {
	if (x<y) swap(x,y);
	ll z;
	while (y) {
		z=x%y;
		x=y;
		y=z;
	}
	return x;
}

int main() {
	int n,ans,i,j,p;
	scanf("%d",&n);mem0(f);
	for (i=1;i<=n;i++) scanf("%d",&a[i]),f[a[i]]=1;
	if (a[1]==1) {
		printf("%d\n",2*n);
		for (i=1;i<=n;i++) printf("%d %d ",1,a[i]);
	} else {
		p=a[1];
		for (i=2;i<=n;i++) p=gcd(p,a[i]);
		if (!f[p]) {
			printf("-1");return 0;
		} else {
			printf("%d\n%d ",2*n+1,p);
			for (i=1;i<=n;i++) printf("%d %d ",a[i],p);
		}
	}
	return 0;
}
