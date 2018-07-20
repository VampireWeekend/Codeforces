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

int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	int ans,i,j;
	if (k!=2) {
		if (n%k==2) ans=(n-2)/k*2+1; else 
	 ans=(n-2)/k*2+2; 
	} else ans=n-1;
	printf("%d\n",ans);
	j=1;i=1;
	int cnt=0;
	while (cnt<n-1) {
		cnt++;
		i++;
		if (j==1) printf("%d %d\n",j,i); else printf("%d %d\n",i-k,i);
		if (cnt%k==0) j=i;
	}
	return 0;
}
