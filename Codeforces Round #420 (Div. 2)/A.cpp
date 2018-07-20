#include <cstdio>
#include <iostream>
#include <string.h> 
using namespace std;
const int maxn=55;
int a[maxn][maxn];

int main() {
	int n,i,j,k,l;
	cin >> n; 
	for (i=1;i<=n;i++) {
		for (j=1;j<=n;j++) {
			cin >> a[i][j];
		}
	}
	int flag=1;
	for (i=1;i<=n;i++) {
		for (j=1;j<=n;j++) {
			int flag1=0;
			for (k=1;k<=n;k++) {
				for (l=1;l<=n;l++) {
					if (a[i][k]+a[l][j]==a[i][j]) flag1=1;
				}
			}
			if (a[i][j]==1) flag1=1;
			flag=flag&flag1;
		}
	}
	if (flag) cout << "Yes"; else cout << "No";
}
