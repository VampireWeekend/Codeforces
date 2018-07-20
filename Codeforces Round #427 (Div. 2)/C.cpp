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
int f[105][105];
int ans[maxn];

struct query{
	int x1,y1,x2,y2,t,id;
};
query q[maxn];

bool cmp(query a,query b) {
	return a.t<b.t;
}

struct star{
	int x,y,s;
};
star a[maxn];

int lowbit(int v) {
	return (v&(-v));
}

void update (int n,int m,int c) {
    int i=n,j=m;
	for (i=n;i<=102;i+=lowbit(i))
	    for (j=m;j<=102;j+=lowbit(j))
	        f[i][j]+=c;
}

int findsum(int n,int m) {
	int i=n,j=m;
	int sum=0;
	for (i=n;i>0;i-=lowbit(i))
	    for (j=m;j>0;j-=lowbit(j))
	        sum+=f[i][j];
	return sum;
}

int main() {
	int n,m,c,i,j;
	mem0(f);
	scanf("%d%d%d",&n,&m,&c);
	for (i=1;i<=n;i++) {
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].s);
		update(a[i].x+1,a[i].y+1,a[i].s);
	} 
	for (i=1;i<=m;i++) {
		scanf("%d%d%d%d%d",&q[i].t,&q[i].x1,&q[i].y1,&q[i].x2,&q[i].y2);
		q[i].id=i;
		q[i].t%=(c+1);
	}
	sort(q+1,q+m+1,cmp);
	int t;j=1,i=1;
	for (t=0;t<=c;t++) {
		while (q[i].t<=t&&i<=m) {
			ans[q[i].id]=findsum(q[i].x2+1,q[i].y2+1)-findsum(q[i].x1,q[i].y2+1)
			-findsum(q[i].x2+1,q[i].y1)+findsum(q[i].x1,q[i].y1);
			i++;
		}
		for (j=1;j<=n;j++) {
			if ((a[j].s+t+1)%(c+1)!=0) {
				update(a[j].x+1,a[j].y+1,1);
			} else {
				update(a[j].x+1,a[j].y+1,-c);
			}
		}
	}
	for (i=1;i<=m;i++) {
		printf("%d\n",ans[i]);
	}
	return 0;
}
