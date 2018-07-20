#include <cstdio>
#include <iostream>
#include <vector>
#include <string.h>
#include <map>
#include <algorithm>
#include <set>
#include <math.h>
#include <cmath>
#include <queue>
using namespace std;
typedef long long ll;
char ma[105][105];

int main() {
	int n,m,i,j;
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++) {
		scanf("%s",ma[i]+1);
	}
	int l=105,r=-1,u=105,d=-1,sum=0;
	for (i=1;i<=n;i++) {
		for (j=1;j<=m;j++) {
			if (ma[i][j]=='B') {
				l=min(j,l);
				r=max(j,r);
				u=min(i,u);
				d=max(i,d);
				sum++;
			}
		}
	}
	if (sum==0) cout << 1 << endl; else {
		int len=max(d-u+1,r-l+1);
		for (i=1;i<=n;i++) {
			for (j=1;j<=m;j++) {
				if (j+len-1>=r&&j<=l&&i+len-1>=d&&i<=u&&i+len-1<=n&&j+len-1<=m) {
				cout << len*len-sum << endl; 
			return 0;
				} 
			}
		}
		cout << -1 << endl; 
	}
	return 0;
}
