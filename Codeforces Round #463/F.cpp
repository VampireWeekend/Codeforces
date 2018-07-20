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
int head[maxn];
bool visit[maxn];
ll dp[maxn],a[maxn],b[maxn];
int num=0;

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

int main() {
	num=0;mem0(visit);
	memset(head,-1,sizeof(head));
	int n,i,j,x,y;
	scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%I64d",&a[i]);
	for (i=1;i<=n;i++) scanf("%I64d",&b[i]);
	for (i=1;i<n;i++) {
		scanf("%d%d",&x,&y);
		addedge(x,y);
	}
	
	return 0;
}
