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
const int maxn=1000000,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int a[maxn];
bool prime[maxn];
int num;

void init() {
	num=0;
	memset(prime,0,sizeof(prime));
	int i,j;
	for (i=2;i<=maxn-1;i++) {
		if (!prime[i]) {
			a[++num]=i;
		}
		for (j=1;j<=num&&i*a[j]<=maxn-1;j++) {
			prime[i*a[j]]=1;
			if (i%a[j]==0) {
				break;
			} 
		}
	}
}

int main() {
	int n,m,i,j,p,q,sum=0,tot=0;
	scanf("%d%d",&n,&m);
	init();
	q=lower_bound(a+1,a+num+1,2+n-2)-a;
	q=a[q];
	printf("%d %d\n",2,q);
	printf("1 %d 2\n",n);
	sum=1;tot=2;int r=0;
	if (sum==m) return 0;
	for (i=1;i<=n-1;i++) {
		for (j=i+1;j<=n;j++) {
			if (i==1&&j==n) continue;
			sum++;
			if (i==1&&j==n-1) {
				printf("%d %d %d\n",i,j,q-tot);
				r=max(2,q-tot)+1;
			}
			else if (i==1) printf("%d %d %d\n",i,j,1),tot++;
				else printf("%d %d %d\n",i,j,r);
			if (sum==m) 
				return 0;
		}
	}
	return 0;
}
