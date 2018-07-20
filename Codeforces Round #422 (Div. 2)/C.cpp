#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=200005;
int pre[maxn],nxt[maxn],s[maxn][20];

struct Val {
	int l,r,cost,len;
};
Val a[maxn];

bool cmp(Val a,Val b) {
	return (a.len<b.len)||(a.len==b.len&&a.l<b.l);
}

int main() {
	int n,i,j,x;
	scanf("%d%d",&n,&x);
	for (i=1;i<=n;i++) {
		scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].cost);
		a[i].len=a[i].r-a[i].l+1;
	}
	int h=1,t=n,ans=2e9+5;
	sort(a+1,a+n+1,cmp);
	pre[1]=1;
	for (i=2;i<=n;i++) {
		if (a[i].len==a[i-1].len) pre[i]=pre[i-1]; else pre[i]=i;
	}
	nxt[n]=n;
	for (i=n-1;i>=1;i--) {
		if (a[i].len==a[i+1].len) nxt[i]=nxt[i+1]; else nxt[i]=i;
	}
	for (i=1;i<=n;i++) s[i][0]=a[i].cost;
	for (j=1;(1<<(j))<=n;j++) {
		for (i=1;i+(1<<j)-1<=n;i++) {
			s[i][j]=min(s[i][j-1],s[i+(1<<(j-1))][j-1]);
		}
	}
	while (a[h].len+a[t].len>x&&t>0) t=pre[t]-1;
	while (h<t) {
		if (a[h].len+a[t].len==x) {
			t=pre[t];h=pre[h];
			for (i=pre[h];i<=nxt[h];i++) {
				while (a[i].r>=a[t].l&&t<nxt[t]) 
					t++;
				if (a[i].r>=a[t].l&&t==nxt[t]) break;
				int k=0,l=t,r=nxt[t];
		        while ((1<<(k+1))<=(r-l+1)) k++;
	    	    int fmin=min(s[l][k],s[r-(1<<k)+1][k]);
				ans=min(ans,fmin+a[i].cost);
			}
			t=nxt[t];h=nxt[h];
			for (i=nxt[h];i>=pre[h];i--) {
				while (a[i].l<=a[t].r&&t>pre[t]) 
					t--;
				if (a[i].l<=a[t].r&&t==pre[t]) break;
				int k=0,l=pre[t],r=t;
		        while ((1<<(k+1))<=(r-l+1)) k++;
	    	    int fmin=min(s[l][k],s[r-(1<<k)+1][k]);
				ans=min(ans,fmin+a[i].cost);
			}
			h=nxt[h]+1;
			t=pre[t]-1;
		} else if (a[h].len+a[t].len<x) h=nxt[h]+1;	else t=pre[t]-1;	
	}
	if (ans==2e9+5) ans=-1;
	printf("%d",ans);
	return 0;
}
/*
10 4
1 1 3
5 5 4
1 2 8
2 3 2
4 5 9
1 3 3
2 4 16
1 4 8
2 5 7
1 5 45
*/
