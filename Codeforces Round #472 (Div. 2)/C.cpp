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
const int maxn=100005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int a[maxn];

int main() {
	int n,u,i,j;
	scanf("%d%d",&n,&u);
	db ans=-1;
	scanf("%d%d",&a[1],&a[2]);
	j=2;
	for (i=3;i<=n;i++) {
		scanf("%d",&a[i]);
		while (j+1<i&&(db)(a[i]-a[j])/(db)(a[i]-a[j-1])<(db)(a[i]-a[j+1])/(db)(a[i]-a[j]))
			j++;
		while (a[i]-a[j-1]>u&&j+1<i) j++;
		if (a[i]-a[j-1]<=u) ans=max(ans,(db)(a[i]-a[j])/(db)(a[i]-a[j-1]));
	}
	if (ans<0) printf("-1"); else printf("%.10lf",ans);
	return 0;
}
