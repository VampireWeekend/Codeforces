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
#include <bitset>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=100005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);
int head[maxn],a[maxn*2],mind[maxn*2][20],f[maxn],d[maxn],dep[maxn*2];
bool visit[maxn];
int dfn,num;

struct Edge {
	int from,to,pre,dist;
};
Edge edge[maxn*2];

void addedge(int from,int to) {
	edge[num]=(Edge){from,to,head[from]};
	head[from]=num++;
	edge[num]=(Edge){to,from,head[to]};
	head[to]=num++;
}

void dfs(int now,int step) {
	visit[now]=1;a[++dfn]=now;f[now]=dfn;dep[dfn]=step;
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to]) {
			d[to]=d[now]+1;
			dfs(to,step+1);
			a[++dfn]=now;
			dep[dfn]=step;
		}
	}
}

void init(int n) {
	int i,j;
	for (i=1;i<=n;i++) mind[i][0]=i;
	for (j=1;(1<<j)<=n;j++) {
		for (i=1;i+(1<<j)-1<=n;i++) {
			int p=mind[i][j-1],q=mind[i+(1<<(j-1))][j-1];
			mind[i][j]=dep[p]<dep[q]?p:q;
		}
	}
}

int find(int l,int r) {
	int k=0;
	if (l>r) {
		int p=l;l=r;r=p;
	}
	while (1<<(k+1)<=(r-l+1)) k++;
	int p=mind[l][k],q=mind[r-(1<<k)+1][k];
	return dep[p]<dep[q]?a[p]:a[q];
}

int main() {
	memset(head,-1,sizeof(head));
	int n,q,i,j,x,y,z;
	scanf("%d%d",&n,&q);
	num=0;
	for (i=1;i<n;i++) {
		scanf("%d",&x);
		addedge(x,i+1);
	}
	mem0(visit);
	d[1]=dfn=0;
	dfs(1,0);
	init(dfn);
	for (i=1;i<=q;i++) {
		scanf("%d%d%d",&x,&y,&z);
		int pxy,pyz,pxz,dxy,dyz,dxz;
		pxz=find(f[x],f[z]);
		pyz=find(f[y],f[z]);
		pxy=find(f[x],f[y]);
		dxy=d[x]+d[y]-2*d[pxy];
		dyz=d[z]+d[y]-2*d[pyz];
		dxz=d[z]+d[x]-2*d[pxz];
		int ans=max(max(dxy+dyz-dxz,dyz+dxz-dxy),dxy+dxz-dyz);
		printf("%d\n",ans/2+1);
	}
	return 0;
}

