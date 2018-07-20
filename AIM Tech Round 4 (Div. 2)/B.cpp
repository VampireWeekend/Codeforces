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
const int maxn=55,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);  
int a[maxn][maxn];
ll p[maxn];

int main() {
//	freopen("F.in","r",stdin);
//	freopen("F.out","w",stdout);
	int n,m,i,j,sum=0;
	ll ans=0;
	scanf("%d%d",&n,&m);
	p[0]=1;
	for (i=1;i<=52;i++) {
		p[i]=p[i-1]*2;
		p[i-1]--;
	}
	for (i=1;i<=n;i++) {
		sum=0;
		for (j=1;j<=m;j++) {
			scanf("%d",&a[i][j]);
			sum+=a[i][j];
		}
		ans+=p[sum]+p[m-sum];
	}
	for (i=1;i<=m;i++) {
		sum=0;
		for (j=1;j<=n;j++) {
			sum+=a[j][i];
		}
		ans+=p[sum]+p[n-sum]-n;
	}
	cout << ans;
	return 0;
}

