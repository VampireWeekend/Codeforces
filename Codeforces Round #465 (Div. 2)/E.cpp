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
const int maxn=10005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
char s[maxn];
int a[maxn],p[maxn];
ll dp[maxn][105][2];
int num=0,x,y;

int dfs(int now,ll l,ll r) {
	if (l==r) {
		dp[now][0][0]=dp[now][0][1]=s[l]-'0';
		return 0;
	} 
	int lc,rc,ls,rs;
	lc=++num;
	ls=dfs(num,l+1,p[l]-1);
	rc=++num;
	rs=dfs(num,p[l]+1,r-1);
	if (x<y)
	for (int i=0;i<=min(x,ls+rs+1);i++) {
		for (int j=0;j<=min(ls,i);j++) {
			if (j!=i)
				dp[now][i][0]=max(dp[now][i][0],dp[lc][j][0]+dp[rc][i-j-1][0]);
			dp[now][i][0]=max(dp[now][i][0],dp[lc][j][0]-dp[rc][i-j][1]);
			if (j!=i)
				dp[now][i][1]=min(dp[now][i][1],dp[lc][j][1]+dp[rc][i-j-1][1]);
			dp[now][i][1]=min(dp[now][i][1],dp[lc][j][1]-dp[rc][i-j][0]);
		}
	}
	else 
	for (int i=0;i<=min(y,ls+rs+1);i++) {
		for (int j=0;j<=min(ls,i);j++) {
			dp[now][i][0]=max(dp[now][i][0],dp[lc][j][0]+dp[rc][i-j][0]);
			if (j!=i)
				dp[now][i][0]=max(dp[now][i][0],dp[lc][j][0]-dp[rc][i-j-1][1]);
			dp[now][i][1]=min(dp[now][i][1],dp[lc][j][1]+dp[rc][i-j][1]);
			if (j!=i)
				dp[now][i][1]=min(dp[now][i][1],dp[lc][j][1]-dp[rc][i-j-1][0]);
		}
	}
	return ls+rs+1;
}

int main() {
	scanf("%s",s+1);
	int len,i,j;
	len=strlen(s+1);
	if (len==1) {
		printf("%s",s+1);return 0;
	} 
	scanf("%d%d",&x,&y);
	stack<int> st;
	for (i=1;i<=len;i++) {
		if (s[i]=='(') st.push(i);
		if (s[i]==')') {
			a[st.top()]=i;
			st.pop();
		}
		if (s[i]=='?') p[st.top()]=i;
	}
	num=1;
	for (i=1;i<=len;i++) {
		for (j=0;j<=min(x,y);j++) {
			dp[i][j][0]=-inf;dp[i][j][1]=inf;
		}
	}
	dfs(1,1,len);
	printf("%I64d\n",dp[1][min(x,y)][0]);
	return 0;
}
