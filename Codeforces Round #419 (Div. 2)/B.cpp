#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
const int maxn=200005;
int a[maxn],sum[maxn],f[maxn];

int lowbit(int x) {
	return (x&(-x));
}

void update (int k,int c) {
	int i;
	for (i=k;i<=maxn-1;i+=lowbit(i)) {
		f[i]+=c;
	}
}

int find (int k) {
	int i,ans=0;
	for (i=k;i>=1;i-=lowbit(i)) {
		ans+=f[i];
	//	cout << ans << ' ' << i << endl;
	} 
	return ans;
}

int main() {
	int n,k,q,l,r,i,j;
	scanf("%d%d%d",&n,&k,&q);
	memset(a,0,sizeof(a));
	for (i=1;i<=n;i++) {
		scanf("%d%d",&l,&r);
		a[l]++;a[r+1]--;
	}
	sum[0]=0;
	for (i=1;i<=maxn-1;i++) {
		sum[i]=sum[i-1]+a[i];
	}
	memset(f,0,sizeof(f));
	for (i=1;i<=maxn-1;i++) {
		if (sum[i]>=k) update(i,1);
	}
	for (i=1;i<=q;i++) {
		scanf("%d%d",&l,&r);
		int ans=find(r);
		ans-=find(l-1);
		printf("%d\n",ans);
	}
	return 0;
}
