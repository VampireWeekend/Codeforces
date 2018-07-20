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
int c[maxn*2],x[maxn],y[maxn];
vector<int> v[maxn*2];
bool visit[maxn*2];

bool dfs(int now,int p) {
	visit[now]=1;
	c[now]=p+1;
	if (!visit[v[now][0]]) dfs(v[now][0],p^1);
		else if (!visit[v[now][1]]) dfs(v[now][1],p^1);
	return true;
}

int main() {
	int n,i,j; 
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		scanf("%d%d",&x[i],&y[i]);
		v[x[i]].push_back(y[i]);
		v[y[i]].push_back(x[i]);
		v[i*2].push_back(i*2-1);
		v[i*2-1].push_back(i*2);
	}
	mem0(visit);
	for (i=1;i<=n*2;i++) {
		if (!visit[i]) dfs(i,0);
	}
	for (i=1;i<=n;i++) {
		printf("%d %d\n",c[x[i]],c[y[i]]);
	}
	return 0;
}
