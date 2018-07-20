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
ll a[maxn];
int tem[maxn];

struct Point{
	int x,y;
};
Point p[maxn];

bool cmp(Point a,Point b) {
	return a.x<b.x || (a.x==b.x&&a.y<b.y);
}

bool cmpy(int a,int b) {
	return p[a].y<p[b].y;
}

ll sqr(ll x) {
	return x*x;
}

ll dfs(int l,int r) {
	if (l==r) return llinf;
	if (l+1==r) return sqr(p[l].x-p[r].x)+sqr(p[l].y-p[r].y);
	int mid=(l+r)/2;
	ll d1=dfs(l,mid),d2=dfs(mid+1,r),ans;
	ans=min(d1,d2);
	int i,j,m=0;
	for (i=l;i<=r;i++) 
		if (sqr(p[i].x-p[mid].x)<=ans) tem[m++]=i;
	sort(tem,tem+m,cmpy);
	for (i=0;i<m;i++) 
		for (j=i+1;j<m&&sqr(p[tem[i]].y-p[tem[j]].y)<ans;j++)
			ans=min(ans,sqr(p[tem[i]].x-p[tem[j]].x)+sqr(p[tem[i]].y-p[tem[j]].y));
	return ans;
}

int main() {
	int n,i;
	scanf("%d",&n);
	ll sum=0;
	for (i=1;i<=n;i++) {
		scanf("%I64d",&a[i]);
		sum+=a[i];
		p[i].x=i;p[i].y=sum;
	}
//	sort(p+1,p+n+1,cmp);
	ll ans=dfs(1,n);
	printf("%I64d\n",ans);
	return 0;
}
