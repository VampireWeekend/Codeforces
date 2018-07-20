#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
const int maxn=100005;
struct fountain{
	int b,p;
};
fountain fc[maxn],fd[maxn];
int ma[maxn][20],mb[maxn][20];

bool cmp(fountain x,fountain y) {
	return (x.p>y.p);
}

int max(int a,int b) {
	if (a>b) return a; else return b;
}

int main() {
	int n,c,d,i,j,p,b,numc=0,numd=0,maxa=-1,maxb=-1,ans=0;
	char ch;
	scanf("%d%d%d",&n,&c,&d);
	for (i=1;i<=n;i++) {
		scanf("%d %d %c",&b,&p,&ch);
		if (ch=='C') {
			if (p<=c) {
				fc[++numc].p=p;
		    	fc[numc].b=b;
		    	maxa=max(maxa,b);
		    	
			}
		} else {	
			if (p<=d) {
				fd[++numd].p=p;
		    	fd[numd].b=b;
		    	maxb=max(maxb,b);
			}
		}
	}
	if (maxa!=-1&&maxb!=-1) ans=maxa+maxb;
	int l,r;
if (maxa!=-1) {
	sort(fc+1,fc+numc+1,cmp);
	for (i=1;i<=numc;i++) ma[i][0]=fc[i].b;
	for (j=1;(1<<(j))<=numc;j++) {
		for (i=1;i+(1<<j)-1<=numc;i++) {
			ma[i][j]=max(ma[i][j-1],ma[i+(1<<(j-1))][j-1]);
		}
	}
	l=1,r=numc+1;
	while (l<r) {
		r--;
		while (fc[l].p+fc[r].p>c&&l<r) l++;
		if (l>=r) break;
		int k=0;
		while ((1<<(k+1))<=(r-l)) k++;
		int fmax=max(ma[l][k],ma[r-(1<<k)][k]);
		ans=max(ans,fmax+fc[r].b);
	}
}
if (maxb!=-1) {
	sort(fd+1,fd+numd+1,cmp);
	for (i=1;i<=numd;i++) mb[i][0]=fd[i].b;
	for (j=1;(1<<(j))<=numd;j++) {
		for (i=1;i+(1<<j)-1<=numd;i++) {
			mb[i][j]=max(mb[i][j-1],mb[i+(1<<(j-1))][j-1]);
		}
	}
	l=1,r=numd+1;
	while (l<r) {
		r--;
		while (fd[l].p+fd[r].p>d&&l<r) l++;
		if (l>=r) break;
		int k=0;
		while ((1<<(k+1))<=(r-l)) k++;
		int fmax=max(mb[l][k],mb[r-(1<<k)][k]);
		ans=max(ans,fmax+fd[r].b);
	}
}
	printf("%d",ans);
	return 0;
}
