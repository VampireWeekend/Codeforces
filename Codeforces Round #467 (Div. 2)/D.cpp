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
int a[maxn],d[maxn];
int dfn[maxn],low[maxn],color[maxn],val[maxn];
bool inst[maxn];
int num=0;
stack<int> st;
vector<int> v[maxn];

void tarjan(int now) {
	num++;
	dfn[now]=low[now]=num;
	inst[now]=1;
	st.push(now);
	for (int i=0;i<v[now].size();i++) {
		int to=v[now][i];
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
		val[cnum]++;
		while (st.top()!=now) {
			color[st.top()]=cnum;
			val[cnum]++;
			inst[st.top()]=0;
			st.pop();
		}
		st.pop();
	}
}

int main() {
	int n,m,x,i,j,y;
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++) {
		scanf("%d",&x);
		for (j=1;j<=x;j++) {
			scanf("%d",&y);
			v[y].push_back(x);
			d[y]++;
		}
	}
	queue<int> q;
	memset(a,-1,sizeof(a));
	for (i=1;i<=n;i++) {
		if (d[i]==0) q.push(i),a[i]=-1;
	}
	while (!q.empty()) {
		
	}
	return 0;
}
