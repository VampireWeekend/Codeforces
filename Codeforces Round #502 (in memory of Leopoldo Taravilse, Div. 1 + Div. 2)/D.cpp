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
#include <assert.h>
#define pb push_back 
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef pair<int,int> pp;
const int maxn=5005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
int per[maxn][15],path[15],w[maxn],cnt[maxn],ans[maxn][105];
char s[maxn];
int num=0;

void dfs(int n,int dep) {
	if (dep==n+1) {
		for (int i=1;i<=n;i++) 
			per[num][i]=path[i];
		num++;
		return;
	}
	path[dep]=0;
	dfs(n,dep+1);
	path[dep]=1;
	dfs(n,dep+1);
}

int main() {
	int n,q,m,k;
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=n;i++) scanf("%d",&w[i]);
	dfs(n,1);
	for (int i=1;i<=m;i++) {
		scanf("%s",s+1);
		int now=0;
		for (int j=1;j<=n;j++) {
			now=now*2+s[j]-'0';
		}
		cnt[now]++;
	}
	for (int i=0;i<num;i++) {
		for (int j=0;j<num;j++) {
			int p=0;
			for (int k=1;k<=n;k++) {
				if (per[j][k]==per[i][k]) p+=w[k];
			}
			if (p<=100) ans[i][p]+=cnt[j];
		}
		for (int j=1;j<=100;j++) ans[i][j]+=ans[i][j-1];
	}
	for (int i=1;i<=q;i++) {
		scanf("%s%d",s+1,&k);
		int now=0;
		for (int j=1;j<=n;j++) {
			now=now*2+s[j]-'0';
		}
		printf("%d\n",ans[now][k]);
	}
	return 0;
}
