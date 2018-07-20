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
const int maxn=505,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
char s[maxn][maxn];

int main() {
	int n,m,i,j;
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++) {
		scanf("%s",s[i]+1);
	}
	int flag=1;
	for (i=1;i<=n;i++) {
		for (j=1;j<=m;j++) {
			if (s[i][j]=='S') {
				if (s[i][j+1]=='W'&&j+1<=m) flag=0;
				if (s[i][j-1]=='W'&&j-1>=1) flag=0;
				if (s[i+1][j]=='W'&&i+1<=n) flag=0;
				if (s[i-1][j]=='W'&&i-1>0) flag=0;
				if (s[i][j+1]=='.'&&j+1<=m) s[i][j+1]='D';
				if (s[i][j-1]=='.'&&j-1>=1) s[i][j-1]='D';
				if (s[i+1][j]=='.'&&i+1<=n) s[i+1][j]='D';
				if (s[i-1][j]=='.'&&i-1>0) s[i-1][j]='D';
			}
		}
	}
	if (!flag) printf("No"); else {
		printf("Yes\n");
		for (i=1;i<=n;i++) {
			for (j=1;j<=m;j++) {
				printf("%c",s[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
