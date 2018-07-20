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
#define N 1000000
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=1000005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f,mod=1e9+7;   
const ld pi=acos(-1.0L);  
ll cnt[maxn],f[maxn],g[maxn];

ll fastpower(ll base,int index) {
	ll k=index,ans=1,l=base;
	while (k) {
		if (k%2) ans*=l;
		ans%=mod;
		k/=2;
		l*=l;
		l%=mod;
	}
	return ans;
}

int main() {
	int n,i,j,x;
	mem0(cnt);
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		scanf("%d",&x);
		cnt[x]++;
	}
	ll k,ans=0;
	for (i=2;i<=N;i++) {
		k=0;
		for (j=i;j<=N;j+=i) {
			k+=cnt[j];
		}
		if (k==0) f[i]=0; else f[i]=k*fastpower(2,k-1);
		f[i]%=mod;
	}
	mem0(g);
	for (i=N;i>1;i--) {
		g[i]=f[i];
		for (j=i*2;j<=N;j+=i) {
			g[i]-=g[j];
			if (g[i]<0) g[i]+=mod;
		}
		ans+=g[i]*((ll)(i));
		ans%=mod;
	}
	printf("%I64d\n",ans);
	return 0;
}

