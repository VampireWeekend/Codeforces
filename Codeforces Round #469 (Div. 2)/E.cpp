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
const int maxn=100005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int head[maxn],a[maxn],d[maxn];
int dfn[maxn],low[maxn],color[maxn],val[maxn];
bool inst[maxn];
vector<int> v[maxn];
stack<int> st;
int num=0,cnum=0;

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
		v[cnum].push_back(now);
		while (st.top()!=now) {
			color[st.top()]=cnum;
			inst[st.top()]=0;
			v[cnum].push_back(st.top());
			st.pop();
		}
		st.pop();
	}
}

int main() {
	memset(head,-1,sizeof(head));
	num=0;
	int n,m,k,i,j,x,y;
	scanf("%d%d%d",&n,&m,&k);
	for (i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (i=1;i<=m;i++) {
		scanf("%d%d",&x,&y);
		if ((a[x]+1)%k==a[y]) addedge(x,y);
		if ((a[y]+1)%k==a[x]) addedge(y,x);
	}
	m=num;num=0;
	mem0(dfn);mem0(low);mem0(color);mem0(inst);
	for (i=1;i<=n;i++)
		if (!dfn[i]) tarjan(i);
	int ans=-1;
	mem0(d);
	for (i=0;i<m;i++) 
		if (color[edge[i].from]!=color[edge[i].to]) 
			d[color[edge[i].from]]++;
	for (i=1;i<=cnum;i++)
		if (d[i]==0) 
			if (ans==-1) ans=i; else 
				if (v[i].size()<v[ans].size()) ans=i;
	printf("%d\n",v[ans].size());
	for (i=0;i<v[ans].size();i++) printf("%d ",v[ans][i]);
	return 0;
}
