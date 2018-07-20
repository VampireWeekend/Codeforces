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
#define N 60
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=1000005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);
int sg[maxn];

int main() {
	int n,x,ans,i,j,last=1;
	ans=0;
	for (i=1;i<=N;i++) {
		for (j=last;j<=last+i;j++) {
			sg[j]=i;
		}
		last=j;
	}
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		scanf("%d",&x);
		ans=ans^sg[x];
	}
	if (ans) printf("NO"); else printf("YES");
	return 0;
}

