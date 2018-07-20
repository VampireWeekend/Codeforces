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
#include <bitset>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=1005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);  
int a[maxn];

int main() {
	int n,m,x,y,i;
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	int ans=0;
	for (i=1;i<=m;i++) {
		scanf("%d%d",&x,&y);
		if (a[x]<a[y]) ans+=a[x]; else ans+=a[y];
	}
	printf("%d\n",ans);
	return 0;
}

