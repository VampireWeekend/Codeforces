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
const int maxn=200005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int deg[maxn],head[maxn]; 
int num=0;

struct Edge {
	int from,to,pre;
};
Edge edge[maxk*2];

void addedge(int from,int to) {
	edge[num]=(Edge){from,to,head[from]};
	head[from]=num++;
	edge[num]=(Edge){to,from,head[to]};
	head[to]=num++;
}

int main() {
	int n,m,i,j,x,y;
	scanf("%d%d",&n,&m);
	memset(head,-1,sizeof(head));
	for (i=1;i<=m;i++) {
		scanf("%d%d",&x,&y);
		addedge(x,y);
		deg[x]++;deg[y]++;
	}
	
	return 0;
}
