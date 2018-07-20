#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
typedef long long ll;
const int maxn=1005;
char a[maxn],b[maxn];
int c[maxn][maxn];

int main() {
	int lena,lenb,i,j,ans;
	scanf("%d%d",&lena,&lenb);
	scanf("%s",a);
	scanf("%s",b);
	ans=10005;
	int pos=-1;
	for (i=0;i<=lenb-lena;i++) {
		int k=0;
		for (j=0;j<lena;j++) {
			if (a[j]!=b[i+j]) {
				k++;
				c[i][k]=j;
			}
		}
		if (k<ans) {
			ans=k;
			pos=i;
		}
	}
	printf("%d\n",ans);
	for (i=1;i<=ans-1;i++) {
		printf("%d ",c[pos][i]+1);
	}
	if (ans!=0) printf("%d",c[pos][ans]+1);
	return 0;
}
