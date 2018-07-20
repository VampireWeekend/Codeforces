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
const int maxn=105,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int a[maxn],in[maxn]; 
ll b[maxn];
bool visit[maxn];
int cn=0;

ll gcd(ll x,ll y) {  
    ll z;  
    if (x<y) swap(x,y);  
    while (y) {  
        z=y;y=x%y;x=z;  
    }  
    return x;  
}  

void dfs(int now) {
	visit[now]=1;
	b[cn]++;
	if (!visit[a[now]]) dfs(a[now]);
}

int main() {
	int n,i,j,t;
	ll ans=1;
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		in[a[i]]++;
	}
	for (i=1;i<=n;i++) {
		if (in[i]!=1) {
			printf("-1\n");
			return 0;
		}
	}
	mem0(visit);
	for (i=1;i<=n;i++) {
		if (!visit[i]) {
			cn++;
			dfs(i);
		}
	}
	for (i=1;i<=cn;i++) {
		if (b[i]%2==0) b[i]/=2;
		ll p=gcd(b[i],ans);
		ans=(b[i]/p)*ans;
	}
	printf("%d\n",ans);
	return 0;
}
