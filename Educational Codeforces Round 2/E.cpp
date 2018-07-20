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
const int maxn=500005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int c[maxn],cnt[maxn],size[maxn],son[maxn],head[maxn];
ll ans[maxn];
bool visit[maxn],big[maxn];
ll sum,mx,num;

struct Edge {
	int from,to,pre;
};
Edge edge[maxn*2];

void addedge(int from, int to) {
	edge[num]=(Edge){from,to,head[from]};
	head[from]=num++;
	edge[num]=(Edge){to,from,head[to]};
	head[to]=num++;
}

int dfs2(int now) {  
    visit[now]=1;son[now]=-1;size[now]=1;  
    for (int i=head[now];i!=-1;i=edge[i].pre) {  
        int to=edge[i].to;  
        if (!visit[to]) {  
            size[now]+=dfs2(to);  
            if (son[now]==-1||size[to]>size[son[now]]) son[now]=to;  
        }  
    }
    if (son[now]!=-1) big[son[now]]=1;
    return size[now];
}  

void add(int now,int fa,int val) {
	cnt[c[now]]+=val;
	if (cnt[c[now]]>mx) {
		mx=cnt[c[now]];sum=c[now];
	} else if (cnt[c[now]]==mx) 
		sum+=(ll)c[now];
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (to!=fa&&!big[to]) add(to,now,val);
	}
}

void dfs(int now,int fa,bool rem) {
	visit[now]=1;
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (to!=fa&&!big[to]) dfs(to,now,0);
	}
	if (son[now]!=-1) dfs(son[now],now,1);
	add(now,fa,1);
	ans[now]=sum;
	if (son[now]!=-1) big[son[now]]=0;
	if (!rem) add(now,fa,-1),sum=mx=0;
}

int main() {
	int n,i,j,x,y;
	num=0;memset(head,-1,sizeof(head));
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		scanf("%d",&c[i]);
	}
	for (i=1;i<n;i++) {
		scanf("%d%d",&x,&y);
		addedge(x,y);
	}
	mem0(visit);mem0(big);
	dfs2(1);
	mem0(visit);sum=mx=0;
	dfs(1,0,0);
	for (i=1;i<=n;i++) 
		printf("%I64d ",ans[i]);
	return 0;
}
