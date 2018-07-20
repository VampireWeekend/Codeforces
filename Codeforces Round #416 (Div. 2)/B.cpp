#include <cstdio>
#include <iostream>
#include <string.h>
#include <algorithm>
const int maxn=10005;
using namespace std;
int a[maxn],b[maxn];

int main() {
	int n,i,m,j,l,r,x;
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	for (i=1;i<=m;i++) {
		scanf("%d%d%d",&l,&r,&x);
		int num=0;
		for (j=l;j<=r;j++) {
			if (a[j]<a[x]) num++;
		}
		if (a[l+num]==a[x]) printf("Yes\n"); else printf("No\n");
	}
	return 0;
}
