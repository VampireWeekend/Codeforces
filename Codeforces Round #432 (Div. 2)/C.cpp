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
const int maxn=1005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int a[maxn][5];
bool f[maxn];

bool judge(int i,int j,int k) {
	int s=0;
	for (int p=1;p<=5;p++) s+=(a[i][p]-a[k][p])*(a[j][p]-a[k][p]);
	if (s<=0) return true; else return false;
}

int main() {
	int n,i,j,k;
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		for (j=1;j<=5;j++) scanf("%d",&a[i][j]);
		f[i]=1;
	}
	if (n>=250) {
		cout << 0;
		return 0;
	}
	for (i=1;i<=n;i++) {
		for (j=1;j<=n;j++) {
			if (j==i) continue;
			for (k=j+1;k<=n;k++) {
				if (k==i||k==j) continue;
				if (!judge(j,k,i)) f[i]=0;
			}
		}
	}
	int ans=0;
	for (i=1;i<=n;i++) {
		if (f[i]) ans++;
	}
	printf("%d\n",ans);
	for (i=1;i<=n;i++) {
		if (f[i]) printf("%d ",i);
	}
	return 0;
}

