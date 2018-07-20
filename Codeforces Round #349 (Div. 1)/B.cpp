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
const int maxn=3005,maxk=5005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int head[maxn],d[maxn][maxn];
int num;

struct Edge {
	int from,to,pre;
};
Edge edge[maxk*2];

struct node{
	int d,to;
};
node pre[maxn][4],nxt[maxn][4];

void addedge(int from,int to) {
	edge[num]=(Edge){from,to,head[from]};
	head[from]=num++;
}

void bfs(int s) {
	d[s][s]=0;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int now=q.front();
		q.pop();
		if (d[s][now]>pre[now][1].d) {
			pre[now][3]=pre[now][2];pre[now][2]=pre[now][1];
			pre[now][1]=(node){d[s][now],s};
		} else if (d[s][now]>pre[now][2].d) {
			pre[now][3]=pre[now][2];
			pre[now][2]=(node){d[s][now],s};
		} else if (d[s][now]>pre[now][3].d) 
			pre[now][3]=(node){d[s][now],s};
		for (int i=head[now];i!=-1;i=edge[i].pre) {
			int to=edge[i].to;
			if (d[s][to]==inf) {
				d[s][to]=d[s][now]+1;
				nxt[s][3]=nxt[s][2];
				nxt[s][2]=nxt[s][1];
				nxt[s][1]=(node){d[s][to],to};
				q.push(to);
			}
		}
	}
} 

int main() {
	int n,m,i,j,k,l,x,y;
	meminf(d);mem0(nxt);mem0(pre);
	memset(head,-1,sizeof(head));
	num=0;
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;i++) {
		scanf("%d%d",&x,&y);
		addedge(x,y);
	}
	for (i=1;i<=n;i++) 
		bfs(i);
	int ans=0,a,b,c,e;
	for (i=1;i<=n;i++) {
		for (j=1;j<=n;j++) {
			if (i==j) continue;
			if (d[i][j]==inf) continue;
			for (k=1;k<=3;k++) {
				if (pre[i][k].to==0||pre[i][k].to==j) continue;
				for (l=1;l<=3;l++) {
					if (nxt[j][l].to==0||nxt[j][l].to==i||nxt[j][l].to==pre[i][k].to) continue;
					int sum=pre[i][k].d+d[i][j]+nxt[j][l].d;
					if (sum>ans) {
						ans=sum;
						a=pre[i][k].to;b=i;c=j;e=nxt[j][l].to;
					}
				}
			}
		}
	}
	printf("%d %d %d %d\n",a,b,c,e);
	return 0;
}
