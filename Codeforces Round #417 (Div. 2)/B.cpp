#include <cstdio>
#include <string.h>
#include <iostream>
#include <string>
using namespace std;
const int maxn=17;
int a[maxn],b[maxn],dp[1<<17],map[maxn][105],pos[1<<17];

int main() {
	int n,m,i,j;
	scanf("%d%d",&n,&m);
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	string s;
	int flag=0;
	for (i=n;i>=1;i--) {
		cin >> s;
		for (j=1;j<=m;j++) {
			if (s[j]=='0') map[i][j]=0; else {
				map[i][j]=1;
				if (a[i]==0) a[i]=j;
				b[i]=j;
			}
		}
		if (a[i]!=0) a[i]=m-a[i]+1;
		if (a[i]!=0&&flag==0) flag=i;
	}
	if (n==1||flag==1) {
		cout << b[1] << endl;
		return 0;
	}
	if (flag==0) {
		cout << 0 << endl;
		return 0;
	}
	int h=0,t=2;
	pos[1]=1;pos[2]=2;
	dp[1]=2*b[1];dp[2]=m+1;
	for (i=2;i<=flag-1;i++) {
		int num=t;
		for (j=h+1;j<=num;j++) {
			if (pos[j]%2) {
				dp[++t]=dp[j]+b[i]*2+1;
				pos[t]=1;
				dp[++t]=dp[j]+m+2;
				pos[t]=2;
			} else {
				dp[++t]=dp[j]+a[i]*2+1;
				pos[t]=2;
				dp[++t]=dp[j]+m+2;
				pos[t]=1;
			}
		}
		h=num;
	}
	int ans=0x3f3f3f3f;
	int num=t;
		for (j=h+1;j<=num;j++) {
			if (pos[j]%2) {
				dp[++t]=dp[j]+b[i]+1;
				pos[t]=1;
				dp[++t]=dp[j]+m+2;
				pos[t]=2;
			} else {
				dp[++t]=dp[j]+a[i]+1;
				pos[t]=2;
				dp[++t]=dp[j]+m+2;
				pos[t]=1;
			}
		}
		h=num;
	for (i=h+1;i<=t;i++) {
		ans=min(ans,dp[i]);
	}
	cout << ans << endl;
	return 0;
}
