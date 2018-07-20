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
int a[maxn];
int p[maxn];

int main() {
	int n,i,j=0,k;
	memset(p,-1,sizeof(p));
	scanf("%d%d",&n,&k);
	p[0]=0;
	if (k==1) {
		for (i=1;i<=n;i++) {
			scanf("%d",&a[i]);
			printf("%d ",a[i]);
		}
		return 0;
	}
	for (i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		if (p[a[i]]!=-1) {
			printf("%d ",p[a[i]]);
		}
		else {
			int o=-1;
			for (j=max(0,a[i]-k+1);;j++) {
				if (p[j]==-1) {
					o=j;break;
				}
				if (p[j]!=-1&&a[i]-p[j]<=k-1) {
					o=p[j];break;
				}
			}
			for (int l=j;l<=a[i];l++) {
				p[l]=o;
			}
			printf("%d ",p[a[i]]);
		}
	}
	return 0;
}
