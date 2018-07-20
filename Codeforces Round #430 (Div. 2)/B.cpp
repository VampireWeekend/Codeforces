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
const int maxn=105,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);  

int sqr(int x) {
	return x*x;
}

int main() {
	int d,R,n,x,y,r,i,ans=0;
	cin >> R >> d >> n;
	int p=d;
	d=R;
	R=R-p;
	for (i=1;i<=n;i++) {
		scanf("%d%d%d",&x,&y,&r);
		if (sqr(x)+sqr(y)>=sqr(R+r)&&sqr(x)+sqr(y)<=sqr(d-r)) ans++;
	}
	printf("%d\n",ans);
	return 0;
}

