
#include<stdio.h>
#include<string.h>
#include<iostream>
#define inf 10000000
using namespace std;
char a[10005];
int dp[10005][105][2];
int p,m,pos;
void dfs()
{
	pos++;
	int now1=pos;
	if(a[pos]!='(')dp[pos][0][0]=dp[pos][0][1]=a[pos]-'0',pos++;
	else dfs();
	pos++;
	int now2=pos;
	if(a[pos]!='(')dp[pos][0][0]=dp[pos][0][1]=a[pos]-'0',pos++;
	else dfs();
	for(int i=0;i<=min(p,m);i++)
		for(int j=0;j<=min(p,m)-i;j++)
		{
			dp[now1-1][i+j+(p>m)][0]=max(dp[now1-1][i+j+(p>m)][0],dp[now1][i][0]-dp[now2][j][1]);
			dp[now1-1][i+j+(p<=m)][0]=max(dp[now1-1][i+j+(p<=m)][0],dp[now1][i][0]+dp[now2][j][0]);
			dp[now1-1][i+j+(p>m)][1]=min(dp[now1-1][i+j+(p>m)][1],dp[now1][i][1]-dp[now2][j][0]);
			dp[now1-1][i+j+(p<=m)][1]=min(dp[now1-1][i+j+(p<=m)][1],dp[now1][i][1]+dp[now2][j][1]);
		}
	pos++;
}
int main()
{
	for(int i=0;i<10005;i++)
		for(int j=0;j<105;j++)
			dp[i][j][0]=-inf,dp[i][j][1]=inf;
	scanf("%s",a);
	int l=strlen(a);
	scanf("%d%d",&p,&m); 
	if(l==1)
	{
		printf("%d\n",a[0]-'0');
		return 0;
	}
	dfs();
	int i,j;
	for (i=11;i<=11;i++) {
		for (j=0;j<=min(p,m);j++) {
			cout << dp[i][j][0] << ' ' << dp[i][j][1] << endl;
		}
		cout << '\n';
	}
	if(pos!=l)while(1);
	if(p<=m)printf("%d\n",dp[0][p][0]);
	else printf("%d\n",dp[0][m][0]);
}
