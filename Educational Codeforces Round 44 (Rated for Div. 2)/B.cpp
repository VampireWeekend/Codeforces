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
int a[maxn];

int main() {
	int n,m,i,j;
	mem0(a);
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++) {
		scanf("%s",s[i]+1);
		for (j=1;j<=m;j++) {
			if (s[i][j]=='1') a[j]++;
		} 
	}
	for (i=1;i<=n;i++) {
		int flag=1;
		for (j=1;j<=m;j++) {
			if (s[i][j]=='1'&&a[j]==1) flag=0;
		}
		if (flag) {
			printf("YES");return 0;
		} 
	}
	printf("NO");
	return 0;
}
