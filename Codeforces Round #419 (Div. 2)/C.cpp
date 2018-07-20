#include <cstdio>
#include <iostream>
using namespace std;
int n,m;
int a[105][105],x[105],y[105];

int main() {
	int i,j,n,m;
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++) 
		for (j=1;j<=m;j++) 
			scanf("%d",&a[i][j]);
	for (i=2;i<=n;i++) 
		for (j=2;j<=m;j++) 
			if ((a[i][j]-a[i-1][j])!=(a[i][j-1]-a[i-1][j-1])) {
				cout << -1;
				return 0;
			}
	for (j=2;j<=m;j++) 
		for (i=2;i<=n;i++) 
			if ((a[i][j]-a[i][j-1])!=(a[i-1][j]-a[i-1][j-1])) {
				cout << -1;
				return 0;
			}
	int ans=0,mi=0x3f3f3f3f,mini=0,minj=0;
	for (i=1;i<=n;i++) 
		for (j=1;j<=m;j++) 
			if (a[i][j]<mi) {
			    mi=a[i][j];
			    mini=i;
			    minj=j;
	    	}
	for (i=1;i<=n;i++) {
		x[i]=a[i][1]-a[mini][1];
		ans+=x[i];
	}
	for (j=1;j<=m;j++) {
		y[j]=a[1][j]-a[1][minj];
		ans+=y[j];
	}
	if (n>m) {
		for (j=1;j<=m;j++) 
			y[j]+=mi;
		ans+=mi*m;
	} else{
		for (i=1;i<=n;i++) 
			x[i]+=mi;
		ans+=mi*n;
	}
	printf("%d\n",ans);
	for (i=1;i<=n;i++) 
		for (j=1;j<=x[i];j++) 
			printf("row %d\n",i);
	for (i=1;i<=m;i++) 
		for (j=1;j<=y[i];j++) 
			printf("col %d\n",i);
	return 0;
}
