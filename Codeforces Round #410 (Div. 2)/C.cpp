#include <cstdio>
#include <iostream>
#include <string.h>
#include <string> 
#include <map>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=100005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int a[maxn];

int gcd(int x,int y) {
	int z;
	if (x<y) swap(x,y);
	while (y) {
		z=y;y=x%y;x=z;
	}
	return x;
}

int main() {
	int n,i,ans=0,g=0;
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		g=gcd(g,a[i]);
	}
	if (g!=1) {
		cout << "YES\n0";
		return 0;
	}
	g=0;
	for (i=1;i<=n;i++) {
		if (a[i]%2==1) g++; else {
			ans+=g/2+(g%2)*2;g=0;
		}
	}
	if (g!=0) ans+=g/2+(g%2)*2;
	printf("YES\n%d\n",ans);
	return 0;
}

