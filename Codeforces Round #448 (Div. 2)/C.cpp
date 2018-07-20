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
const ll llinf=0x3f3f3f3f3f3f3f3f,mod=1e9+7;   
const ld pi=acos(-1.0L);
ll a[maxn],r[25][maxn];
ll p[20]={2,3,5,7,11,13,15,17,19,23,29,31,37,41,43,47,53,59,61,67};
int num=20;

ll fastpower(ll base,ll index) {
	ll ans,now;
	if (index<=0) return 1;
	ans=1;
	now=base;
	ll k=index;
	while (k) {
		if (k%2) ans=ans*now;
		ans%=mod;
		now=now*now;
		now%=mod;
		k/=2;
	}
	return ans;
}

ll gauss(int n,int m) {
	int i,j,k,l;
	i=j=0;
	while (i<n&&j<m) {
		int q=-1;
		for (k=i;k<n;k++) 
			if (r[k][j]) {
				q=k;break;
			}
		if (q==-1) {
			j++;continue;
		}
		for (k=j;k<m;k++) swap(r[i][k],r[q][k]);
		for (k=i+1;k<n;k++) {
			if (r[k][j])
				for (l=j;l<m;l++) r[k][l]^=r[i][l];
		}
		i++;
	}
	return i;         //有界变量数量即为消元次数 
}

int main() {
	int n,i,j;
	scanf("%d",&n);
	mem0(r);
	for (i=0;i<n;i++) {
		scanf("%I64d",&a[i]);
		for (j=0;j<num;j++) {
			while (a[i]%p[j]==0) {
				a[i]/=p[j];
				r[j][i]^=1;
			}
		}
	}
	ll w=n-gauss(num,n);
	ll ans=fastpower(2,w)-1;
	printf("%I64d\n",ans);
	return 0;
}
