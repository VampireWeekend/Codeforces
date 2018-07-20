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
const int maxn=300005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int head[maxn],deg[maxn];
int dfn[maxn],low[maxn],color[maxn];
int dp[maxn][26];
bool inst[maxn];
char s[maxn];
int num=0,cnum=0;
stack<int> st;

struct Edge {
	int from,to,pre;
};
Edge edge[maxn*2];

void addedge(int from,int to) {
	edge[num]=(Edge){from,to,head[from]};
	head[from]=num++;
}

void tarjan(int now) {
	num++;
	dfn[now]=low[now]=num;
	inst[now]=1;
	st.push(now);
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!dfn[to]) {
			tarjan(to);
			low[now]=min(low[now],low[to]);
		}
		else if (inst[to]) 
		    low[now]=min(low[now],dfn[to]); 
	}
	if (dfn[now]==low[now]) {
		inst[now]=0;
		color[now]=++cnum;
//		val[cnum]++;
		while (st.top()!=now) {
			color[st.top()]=cnum;
//			val[cnum]++;
			inst[st.top()]=0;
			st.pop();
		}
		st.pop();
	}
}

int main() {
	int n,m,i,j,x,y;
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	num=0;
	mem0(deg);
	memset(head,-1,sizeof(head));
	for (i=1;i<=m;i++) {
		scanf("%d%d",&x,&y);
		addedge(x,y);
		if (x==y) {
			printf("-1\n");return 0;
		}
		deg[y]++;
	}
	mem0(dfn);mem0(low);mem0(color);mem0(inst);
	num=cnum=0;
	for (i=1;i<=n;i++) {
		if (!color[i]) tarjan(i);
	}
	if (cnum!=n) {
		printf("-1\n");return 0;
	}
	queue<int> q;
	mem0(dp);
	int ans=0;
	for (i=1;i<=n;i++) {
		if (!deg[i]) q.push(i),dp[i][s[i]-'a']++,ans=max(ans,dp[i][s[i]-'a']);
	}
	while (!q.empty()) {
		int now=q.front();
		q.pop();
		for (i=head[now];i!=-1;i=edge[i].pre) {
			int to=edge[i].to;
			for (j=0;j<26;j++) {
				if (s[to]-'a'==j)
					dp[to][j]=max(dp[to][j],dp[now][j]+1);
				else 
					dp[to][j]=max(dp[to][j],dp[now][j]);
				ans=max(ans,dp[to][j]);
			}
			deg[to]--;
			if (deg[to]==0) q.push(to);
		}
	}
	printf("%d\n",ans);
	return 0;
}
