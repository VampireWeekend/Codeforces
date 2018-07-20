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
const int maxn=2005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
char s[maxn][maxn];

int main() {
	int n,m,k,i,j,ans=0;
	scanf("%d%d%d",&n,&m,&k);
	if (k==1) {
		for (i=1;i<=n;i++) {
			scanf("%s",s[i]+1);
		}
		int ans=0;
		for (i=1;i<=n;i++) {
			for (j=1;j<=m;j++) {
				if (s[i][j]=='.') ans++;
			}
		}
		cout << ans;
		return 0;
	}
	for (i=1;i<=n;i++) {
		scanf("%s",s[i]+1);
		int con=0;
		for (j=1;j<=m;j++) {
			if (s[i][j]=='.') con++; else {
				if (con>=k) ans+=con-k+1;
				con=0;
			}
		}
		if (con>=k) ans+=con-k+1;
	}
	for (i=1;i<=m;i++) {
		int con=0;
		for (j=1;j<=n;j++) {
			if (s[j][i]=='.') con++; else {
				if (con>=k) ans+=con-k+1;
				con=0;
			}
		}
		if (con>=k) ans+=con-k+1;
	}
	printf("%d\n",ans);
	return 0;
}
