#include <cstdio>
#include <iostream>
#include <string.h>
#include <queue>
#include <algorithm>
#include <stack>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=1000005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
int head[maxn],col[maxn],dfn[maxn],low[maxn],x[maxn],y[maxn];
ll d[maxn],sum[maxn],su[maxn],dp[maxn],val[maxn];
bool inst[maxn];
stack<int> st;
int num=0,cnum=0;

struct Edge {
	int from,to,pre;
	ll dist;
};
Edge edge[maxn*2];

void addedge(int from,int to,ll dist) {
	edge[num]=(Edge){from,to,head[from],dist};
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
		col[now]=++cnum;
		while (st.top()!=now) {
			col[st.top()]=cnum;
			inst[st.top()]=0;
			st.pop();
		}
		st.pop();
	}
}

int main() {
	int n,m,i,j,s,cnt=0;
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	su[0]=sum[0]=0;
	for (i=1;su[i-1]<=1e8;i++) {
		cnt++;
		su[i]=su[i-1]+i;
		sum[i]=sum[i-1]+su[i];
	}
	for (i=1;i<=m;i++) {
		scanf("%d%d%I64d",&x[i],&y[i],&d[i]);
		addedge(x[i],y[i],d[i]);
	}
	scanf("%d",&s);
	num=0;
	for (i=1;i<=n;i++) {
		if (!dfn[i]) tarjan(i);
	}
	memset(head,-1,sizeof(head));
	num=0;mem0(dfn);
	ll hk;
	for (i=1;i<=m;i++) {
		if (col[x[i]]==col[y[i]]) {
			ll pos=(ll)(lower_bound(su,su+cnt+1,d[i])-su);
			if (pos<=0) hk=0; else hk=pos*d[i]-sum[pos-1];
			val[col[x[i]]]+=hk;
		} else {
			addedge(col[y[i]],col[x[i]],d[i]);
			dfn[col[x[i]]]++;
		}
	}
	queue<int> q;
	mem0(inst);
	for (i=1;i<=cnum;i++) {
		if (dfn[i]==0) q.push(i),inst[i]=1;
	}
	while (!q.empty()) {
		int now=q.front();
		q.pop();
		dp[now]+=val[now];
		for (i=head[now];i!=-1;i=edge[i].pre) {
			int to=edge[i].to;
			dfn[to]--;
			if (dfn[to]==0) {
				q.push(to);inst[to]=1;
			}
			dp[to]=max(dp[to],dp[now]+edge[i].dist);
		}
	}
	printf("%I64d\n",dp[col[s]]);
	return 0;
}
