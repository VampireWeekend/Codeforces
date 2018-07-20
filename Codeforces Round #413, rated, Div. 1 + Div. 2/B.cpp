#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int top[4];
int buy[200005];
struct cloth{
	int p,a,b;
};
cloth c[200005];

bool cmp(cloth x,cloth y) {
	return (x.p<y.p);
}

int main() {
	int n,m,i;
	scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%d",&c[i].p);
	for (i=1;i<=n;i++) 
		scanf("%d",&c[i].a);
	for (i=1;i<=n;i++) {
		scanf("%d",&c[i].b);
		buy[i]=0;
    }
    buy[n+1]=0;
	sort(c+1,c+n+1,cmp);
	int k;
	for (i=1;i<=3;i++) {
		k=1;
        while (c[k].a!=i&&c[k].b!=i&&k<=n) 
            k++;
        top[i]=k;
    }
	scanf("%d",&m);
	int d;
	for (i=1;i<=m;i++) {
		scanf("%d",&d);
		if (top[d]<=n) {
			printf("%d ",c[top[d]].p);
			int x=top[d];
			buy[top[d]]=1;
			if (x==top[c[x].a]) {
				top[c[x].a]++;
			while ((c[top[c[x].a]].a!=c[x].a&&c[top[c[x].a]].b!=c[x].a&&top[c[x].a]<=n)||(buy[top[c[x].a]])) 
		        top[c[x].a]++;
			}
			if (x==top[c[x].b]) {
		    top[c[x].b]++;
		    while ((c[top[c[x].b]].a!=c[x].b&&c[top[c[x].b]].b!=c[x].b&&top[c[x].b]<=n)||(buy[top[c[x].b]])) 
		        top[c[x].b]++;
		    }
		} else printf("-1 ");
	}
    return 0;
} 
