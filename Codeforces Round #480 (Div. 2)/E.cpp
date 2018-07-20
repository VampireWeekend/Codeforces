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
const int maxn=1000005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int head[maxn];
int num=0;
bool visit[maxn],ch[maxn];
priority_queue<int> pq;
vector<int> v[maxn];

void addedge(int from, int to) {
	v[from].push_back(to);
	v[to].push_back(from);
}

int main() {
	int n,k,i,j,x,y;
	scanf("%d%d",&n,&k);
	num=0;mem0(visit);mem0(ch);
	memset(head,-1,sizeof(head));
	for (i=1;i<n;i++) {
		scanf("%d%d",&x,&y);
		addedge(x,y);
	}
	pq.push(n);
	visit[n]=1;
	for (i=1;i<=n-k;i++) {
		int now=pq.top();
		pq.pop();
		ch[now]=1;
		for (j=0;j<v[now].size();j++) {
			int to=v[now][j];
			if (!visit[to]) pq.push(to),visit[to]=1;
		}
	}
	for (i=1;i<=n;i++) {
		if (!ch[i]) printf("%d ",i);
	}
	return 0;
}
