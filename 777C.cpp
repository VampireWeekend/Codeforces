#include <cstdio>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
vector<int> a[100001];
vector<int> c[100001];
int ans[100001];

int main () {
	int i,j,k,m,n,x,y,pre,min;
	cin >> n >> m;
	for (i=1;i<=n;i++) {
		for (j=1;j<=m;j++) {
			cin >> k;
			a[j].push_back(k);
		}
		ans[i]=-1;
	}
	for (j=1;j<=m;j++) {
		pre=0;
		c[j].push_back(0);
		for (i=1;i<=n-1;i++) {
			if (a[j][i]<a[j][i-1]) {
				c[j].push_back(i);
				pre=i;
			} else c[j].push_back(pre);
		}
	}
	cin >> k;
	for (i=1;i<=k;i++) {
		cin >> x >> y;
		if (ans[y]==-1) {
			int can=0;
			min=100001;
			for (j=1;j<=m;j++){
				if (c[j][y-1]<=x-1) 
					can=1;
				if (c[j][y-1]<min) min=c[j][y-1];
			}
			if (can) cout << "Yes" << endl; else cout << "No" << endl;
			ans[y]=min;
		} else if (ans[y]<=x-1) cout << "Yes" << endl; else cout << "No" << endl;
	}
	return 0;
} 
