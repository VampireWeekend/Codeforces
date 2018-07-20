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
const int maxn=200005, inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
int l[maxn],r[maxn],col[maxn],a[maxn],head[maxn],d[maxn];
bool use[maxn],visit[maxn];
int num;

struct Edge {
	int from,to,pre,id;
};
Edge edge[maxn*2];

void addedge(int from,int to,int l) {
	edge[num]=(Edge){from,to,head[from],l};
	head[from]=num++;
	edge[num]=(Edge){to,from,head[to],l};
	head[to]=num++;
}

void dfs(int now) {
	visit[now]=1;
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		if (use[i/2]) continue;
		use[i/2]=true;
		dfs(edge[i].to);
		if (edge[i].from<edge[i].to) col[edge[i].id]=0; else col[edge[i].id]=1;
	}
}

int main() {
	int n,i,j,m;
	num=0;memset(head,-1,sizeof(head));
	scanf("%d",&n);
	for (i=0;i<n;i++) {
		scanf("%d%d",&l[i],&r[i]);
		r[i]++;
		a[i*2]=l[i];a[i*2+1]=r[i];
	}
	sort(a,a+n*2);
	m=unique(a,a+n*2)-a;
	for (i=0;i<n;i++) {
		l[i]=lower_bound(a,a+m,l[i])-a;
		r[i]=lower_bound(a,a+m,r[i])-a;
		addedge(l[i],r[i],i);
		d[l[i]]++;d[r[i]]++;
	}
	int last=-1,ec=n;
	for (i=0;i<m;i++) {
		if (d[i]%2==1) {
			if (last!=-1) addedge(last,i,ec++),last=-1; else last=i;
		}
	}
	mem0(use);mem0(visit);
	for (i=0;i<m;i++) {
		if (!visit[i]) {
			visit[i]=1;
			dfs(i);
		}
	}
	for (i=0;i<n;i++) printf("%d ",col[i]);
	return 0;
}

