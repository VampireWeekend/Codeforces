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
const int maxn=1000005,maxm=100005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
ll dist[maxn],ans[maxm];
vector<ll> d[maxn],qd[maxn],id[maxn],sum[maxn];
int num=0;

int main() {
	int n,m,i,j,x;
	ll y;
	scanf("%d%d",&n,&m);
	dist[1]=0;
	for (i=2;i<=n;i++) scanf("%I64d",&dist[i]);
	for (i=1;i<=m;i++) {
		scanf("%d%I64d",&x,&y);
		qd[x].push_back(y);
		id[x].push_back(i);
	}
	d[1].push_back(0);
	for (i=2;i<=n;i++) {
		int now;ll pre;
		now=i;pre=0;
		while (now) {
			d[now].push_back(pre);
			pre+=dist[now];now/=2;
		}
	}
	for (i=1;i<=n;i++) {
		sort(d[i].begin(),d[i].end());
		sum[i].push_back(d[i][0]);
		for (j=1;j<d[i].size();j++) 
			sum[i].push_back(sum[i][j-1]+d[i][j]);
	}
	mem0(ans);
	for (i=1;i<=n;i++) {
		for (j=0;j<qd[i].size();j++) {
			int now=i,last,q;ll rem=qd[i][j];
			ll pos=(ll)(lower_bound(d[now].begin(),d[now].end(),rem)-d[now].begin());
			if (pos!=0)
				ans[id[i][j]]+=rem*pos-sum[now][pos-1];
			last=i;rem-=dist[now];now/=2;
			while (now) {
				if (rem>=0) ans[id[i][j]]+=rem;
				if (last==now*2) q=now*2+1; else q=now*2;
				if (q<=n) {
					ll pos=(ll)(lower_bound(d[q].begin(),d[q].end(),rem-dist[q])-d[q].begin());
					if (pos!=0)
						ans[id[i][j]]+=(rem-dist[q])*pos-sum[q][pos-1];
				}
				rem-=dist[now];last=now;now/=2;
			}
		}
	}
	for (i=1;i<=m;i++) printf("%I64d\n",ans[i]);
	return 0;
}
