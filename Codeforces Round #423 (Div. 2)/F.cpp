#include <cstdio>
#include <iostream>
#include <string.h>
#include <string> 
#include <map>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=200005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);  
int f[maxn],mxlen[maxn][20],mnlen[maxn][20],dep[maxn],fa[maxn][20],ans[maxn];
bool use[maxn],visit[maxn];
int num;
vector<int> v[maxn];
vector<int> d[maxn];

struct Edge {
	int from,to,dist,id;
};
Edge edge[maxn*2];

bool cmp(Edge a,Edge b) {
	return a.dist<b.dist; 
} 

int find(int x) {
	if (f[x]==x) return x; else {
		f[x]=find(f[x]);
		return f[x];
	}
}

void kruskal(int n,int m) {
	int cnt=0,i;
	for (i=1;i<=n;i++) f[i]=i;
	mem0(use);
	for (i=1;i<=m;i++) {
		int from=edge[i].from,to=edge[i].to;
		int fa=find(from),fb=find(to);
		if (fa!=fb) {
			cnt++;use[i]=1;
			v[from].push_back(to);
			v[to].push_back(from);
			d[from].push_back(edge[i].dist);
			d[to].push_back(edge[i].dist);
			if (cnt==n-1) return;
			f[fa]=fb;
		}
	}
}

void dfs(int now,int step) {
	visit[now]=1;dep[now]=step;
	for (int i=0;i<v[now].size();i++) {
		int to=v[now][i];
		if (!visit[to]) {
			fa[to][0]=now;mxlen[to][0]=d[now][i];
			dfs(to,step+1);
		}
	}
}

int getmaxlen(int x,int y) {
	if (dep[x]<dep[y]) swap(x,y);
	int i,ans=-inf;
	for (i=18;i>=0;i--) {
		if (dep[fa[x][i]]>=dep[y]) {
			ans=max(ans,mxlen[x][i]);
			x=fa[x][i]; 
		}
	}
	if (x==y) return ans;
	for (i=18;i>=0;i--) {
		if (fa[x][i]!=fa[y][i]) {
			ans=max(ans,max(mxlen[x][i],mxlen[y][i]));
			x=fa[x][i];y=fa[y][i];
		}
	}
	ans=max(ans,max(mxlen[x][0],mxlen[y][0]));
	return ans;
}

void update(int x,int y,int val) {
	if (dep[x]<dep[y]) swap(x,y);
	int i;
	for (i=18;i>=0;i--) {
		if (dep[fa[x][i]]>=dep[y]) {
			mnlen[x][i]=min(val,mnlen[x][i]);
			x=fa[x][i]; 
		}
	}
	if (x==y) return;
	for (i=18;i>=0;i--) {
		if (fa[x][i]!=fa[y][i]) {
			mnlen[x][i]=min(mnlen[x][i],val);
			mnlen[y][i]=min(mnlen[y][i],val);
			x=fa[x][i];y=fa[y][i];
		}
	}
	mnlen[x][0]=min(mnlen[x][0],val);
	mnlen[y][0]=min(mnlen[y][0],val);
}

int main() {
	num=0;
	int n,m,i,j,x,y,d;
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;i++) {
		scanf("%d%d%d",&edge[i].from,&edge[i].to,&edge[i].dist);
		edge[i].id=i;
	}
	sort(edge+1,edge+m+1,cmp);
	kruskal(n,m);
	mem0(visit);
	fa[1][0]=0;dep[0]=-1;
	dfs(1,0);    //binary lifts
	for (j=1;j<=18;j++) {
		for (i=1;i<=n;i++) {
			fa[i][j]=fa[fa[i][j-1]][j-1];
			mxlen[i][j]=max(mxlen[i][j-1],mxlen[fa[i][j-1]][j-1]);
		}
	}
	meminf(ans);meminf(mnlen);
	for (i=1;i<=m;i++) {
		if (!use[i]) {
			ans[edge[i].id]=getmaxlen(edge[i].from,edge[i].to)-1;
			update(edge[i].from,edge[i].to,edge[i].dist-1);
		}
	}
	for (j=17;j>=0;j--) {
		for (i=1;i<=n;i++) {
			mnlen[i][j]=min(mnlen[i][j],mnlen[i][j+1]);
			mnlen[fa[i][j]][j]=min(mnlen[fa[i][j]][j],mnlen[i][j+1]);
		}
	}
	for (i=1;i<=m;i++) {
		if (use[i]) 
		    if (fa[edge[i].from][0]==edge[i].to) 
		        ans[edge[i].id]=mnlen[edge[i].from][0];
		    else 
		        ans[edge[i].id]=mnlen[edge[i].to][0];
	}
	for (i=1;i<=m;i++) {
		if (ans[i]==inf) printf("-1 "); else printf("%d ",ans[i]);
	}
	return 0;
}

