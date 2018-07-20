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
const int maxn=1000005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int a[maxn],cnt[maxn][10];

int main() {
	int i,n,q,j;
	scanf("%d",&q);
	for (j=1;j<=9;j++) cnt[0][j]=0;
	for (i=1;i<10;i++) {
		a[i]=i;
		for (j=1;j<=9;j++) {
			if (a[i]==j) cnt[i][j]=cnt[i-1][j]+1; else cnt[i][j]=cnt[i-1][j];
		}
	}
	for (i=10;i<=1e6;i++) {
		int p=i,sum=1;
		while (true) {
			sum=1;
			while (p) {
				if (p%10) sum*=(p%10);
				p/=10;
			}
			if (sum<i) break;
		}
		a[i]=a[sum];
		for (j=1;j<=9;j++) {
			if (a[i]==j) cnt[i][j]=cnt[i-1][j]+1; else cnt[i][j]=cnt[i-1][j];
		}
	}
	int l,r,k;
	for (i=1;i<=q;i++) {
		scanf("%d%d%d",&l,&r,&k);
		int ans=cnt[r][k]-cnt[l-1][k];
		printf("%d\n",ans);
	}
	return 0;
}
