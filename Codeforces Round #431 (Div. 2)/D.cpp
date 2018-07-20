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
#include <stack>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=100005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int x[maxn],y[maxn],b[maxn],c[maxn];

struct Dancer {
	int g,p,t,id;
};
Dancer a[maxn];

bool cmp(Dancer a,Dancer b) {
	return a.t-a.p<b.t-b.p || (a.t-a.p==b.t-b.p&&a.p<b.p);
}

int main() {
	int n,m,k,i,j;
	scanf("%d%d%d",&k,&n,&m);
	for (i=1;i<=k;i++) {
		scanf("%d%d%d",&a[i].g,&a[i].p,&a[i].t);
		a[i].id=i;
	}
	sort(a+1,a+k+1,cmp);
	for (i=1;i<=k;i++) {
		int t1,t2,cnt;
		t1=t2=0;
		if (a[i].g==1) b[++t1]=i; else c[++t2]=i;
		while (a[i].t-a[i].p==a[i+1].t-a[i+1].p&&i<k) {
			i++;
			if (a[i].g==1) b[++t1]=i; else c[++t2]=i;
		}
		cnt=t2+1;int flag=0;
		for (j=1;j<=t1;j++) {
			if (!flag) cnt--; else cnt++;
			if (cnt==0) cnt++,flag=1;
			if (!flag) x[a[c[cnt]].id]=a[b[j]].p,y[a[c[cnt]].id]=m; 
			    else x[a[b[cnt]].id]=a[b[j]].p,y[a[b[cnt]].id]=m;
		}
		cnt=t1+1;flag=0;
		for (j=1;j<=t2;j++) {
			if (!flag) cnt--; else cnt++;
			if (cnt==0) cnt++,flag=1;
			if (!flag) x[a[b[cnt]].id]=n,y[a[b[cnt]].id]=a[c[j]].p; 
			    else x[a[c[cnt]].id]=n,y[a[c[cnt]].id]=a[c[j]].p;
		}
	}
	for (i=1;i<=k;i++) 
		printf("%d %d\n",x[i],y[i]);
	return 0;
}

