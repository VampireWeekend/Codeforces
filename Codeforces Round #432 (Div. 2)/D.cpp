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
typedef double db;
const int maxn=2000005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
ll a[maxn],b[maxn],cnt[maxn],sum[maxn];
bool prime[maxn];
int num;

void init() {
	num=0;
	mem0(prime);
	int i,j;
	for (i=2;i<=N;i++) {
		if (!prime[i]) 
			a[++num]=i;
		for (j=1;j<=num&&i*a[j]<=N;j++) {
			prime[i*a[j]]=1;
			if (i%a[j]==0) 
				break;
		}
	}
}

int main() {
	int n,i,j;
	ll x,y,ans,f,c;
	scanf("%d%I64d%I64d",&n,&x,&y);
	mem0(cnt);mem0(sum);
	for (i=1;i<=n;i++) {
		scanf("%I64d",&f);
		sum[f]+=f;
		cnt[f]++;
	}
	init();
	for (i=1;i<=N*2;i++) {
		sum[i]+=sum[i-1];
		cnt[i]+=cnt[i-1];
	}
	ans=llinf;
	for (i=1;i<=num;i++) {
		c=0;
		for (j=a[i];j-a[i]<=N;j+=a[i]) {
			f=max(j-x/y-1,j-a[i]);
			c+=(cnt[f]-cnt[j-a[i]])*x+((cnt[j]-cnt[f])*j-sum[j]+sum[f])*y;
		}
		ans=min(ans,c);
	}
	printf("%I64d\n",ans);
	return 0;
}

