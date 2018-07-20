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
#define pb push_back 
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=10005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
ll c[maxn];
bool dp[maxn][2],z[maxn];

struct query{
	int l,r,val;
};
query a[maxn*2];

bool cmp(query a,query b) {
	return a.l<b.l || (a.l==b.l&&a.r<b.r);
}

int main() {
	int n,q,i,j,x,y,p;
	scanf("%d%d",&n,&q);
	mem0(z);
	for (i=1;i<=q;i++) {
		scanf("%d%d%d",&x,&y,&p);
		a[i*2-1].l=x;a[i*2-1].val=p;a[i*2-1].r=1;
		a[i*2].l=y+1;a[i*2].val=p;a[i*2].r=-1;
	}
	sort(a+1,a+q*2+1,cmp);
	x=0,y=1;
	dp[0][0]=1;
	for (i=1;i<=q*2;i++) {
		swap(x,y);
		dp[0][x]=1;
		if (a[i].r==-1) {
			for (j=1;j<=n;j++) {
				if (j+a[i].val<=n) {
					if (dp[j+a[i].val][y]) {
						dp[j][x]=1;
					} else dp[j][x]=0;
				}
				else dp[j][x]=0;
			}
		} else {
			for (j=1;j<=n;j++) {
				if (j-a[i].val>=0) {
					if (dp[j-a[i].val][y]) 
						dp[j][x]=1,z[j]=1; else dp[j][x]=0;
				}
				else dp[j][x]=0;
				if (dp[j][y]) dp[j][x]=1;
			}
		}
	}
	int cnt=0;
	for (i=1;i<=n;i++) if (z[i]) cnt++;
	printf("%d\n",cnt);
	for (i=1;i<=n;i++) if (z[i]) printf("%d ",i);
	return 0;
}
