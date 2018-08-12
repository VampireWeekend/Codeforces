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
#include <assert.h>
#define pb push_back 
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef pair<int,int> pp;
const int maxn=1005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
ll a[maxn],b[maxn],ans[maxn][maxn];

int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),a[0]^=a[i];
	for (int i=1;i<=m;i++) scanf("%d",&b[i]),b[0]^=b[i];
	if (a[0]!=b[0]) {
		printf("NO\n");return 0;
	}
	printf("YES\n");
	ans[1][m]=b[0];
	for (int i=1;i<m;i++) ans[1][i]=b[i],ans[1][m]^=b[i];
	for (int i=2;i<=n;i++) ans[i][1]=a[i];
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) printf("%d ",ans);
printf("\n");}
	return 0;
}
