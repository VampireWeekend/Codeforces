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
typedef double db;
const int maxn=100005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);

int gcd(int x,int y) {
	int z;
	if (x<y) swap(x,y);
	while (y) {
		z=y;y=x%y;x=z;
	}
	return x;
}

int main() {
	int n,i,j;
	scanf("%d",&n);
	for (i=n/2,j=n-i;i>0&&j<n;i--,j++) {
		if (gcd(i,j)==1) {
			printf("%d %d\n",i,j);
			return 0;
		}
	}
	return 0;
}

