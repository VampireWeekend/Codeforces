#include <cstdio>
#include <iostream>
#include <string.h>
#include <string> 
#include <map>
#include <unordered_map>
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
int c[maxn],cnt[maxn],siz[maxn],son[maxn],head[maxn],ans[maxn],dep[maxn];
bool visit[maxn],big[maxn];
unordered_map<string,int> mp;
map<int, int> mp2[maxn];
ll sum,mx,num;
int n,m;

struct query{
	int id,d;
	query(int id,int d): id(id),d(d) {}
};
vector<query> q[maxn];

struct Edge {
	int from,to,pre;
};
Edge edge[maxn*2];

void addedge(int from, int to) {
	edge[num].from = from; edge[num].to = to;
	edge[num].pre = head[from]; head[from] = num++;
}

int dfs2(int now,int step) {  
	visit[now] = 1; son[now] = -1; siz[now] = 1; dep[now] = step;
    for (int i=head[now];i!=-1;i=edge[i].pre) {  
        int to=edge[i].to;  
        if (!visit[to]) {  
            siz[now]+=dfs2(to,step+1);  
            if (son[now]==-1||siz[to]>siz[son[now]]) son[now]=to;  
        }  
    }
    if (son[now]!=-1) big[son[now]]=1;
    return siz[now];
}  

void add(int now, int val) {
	int w;
	w = mp2[dep[now]][c[now]] += val;
	if (w == 0&&val==-1) cnt[dep[now]]--; 
	if (w == 1&&val==1) cnt[dep[now]]++;
	for (int i = head[now]; i != -1; i = edge[i].pre) {
		int to = edge[i].to;
		if (!big[to]) add(to, val);
	}
}

void dfs(int now,int fa,bool rem) {
	int i;
	for (i = head[now]; i != -1; i = edge[i].pre) {
		int to = edge[i].to;
		if (to != fa && !big[to]) dfs(to, now, 0);
	}
	if (son[now] != -1) dfs(son[now], now, 1);
	add(now, 1);
	for (i = 0; i < q[now].size(); i++) {
		if (q[now][i].d + dep[now]<=1e5) ans[q[now][i].id] = cnt[q[now][i].d+dep[now]];
		else ans[q[now][i].id] = 0;
	}
	if (son[now] != -1) big[son[now]] = 0;
	if (!rem) add(now, -1);
}

int main() {
	num=0;memset(head,-1,sizeof(head));
	int n,i,j,m=0,x,y,qn;
	string s;
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		cin >> s >> x;
		if (!mp[s]) c[i]=mp[s]=++m; else c[i]=mp[s];
		addedge(x,i);
	}
	scanf("%d",&qn);
	for (i=1;i<=qn;i++) {
		scanf("%d%d",&x,&y);
		q[x].push_back(query(i,y));
	} 
	mem0(visit);mem0(big);
	dfs2(0,0);
	mem0(cnt);
	dfs(0, -1, 0);
	for (i = 1; i <= qn; i++) printf("%d\n", ans[i]);
	return 0;
}
