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
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=1005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
ll y[maxn];
bool f[maxn];

int main() {
	int n,i,j;
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		scanf("%lld",&y[i]);
	}
	for (i=2;i<=n;i++) {
		mem0(f);
		f[1]=f[i]=1;
		int cnt=2,u=0;
		for (j=2;j<=n;j++) {
			if (j==i) continue;
			if ((y[j]-y[1])*(i-1)==(y[i]-y[1])*(j-1)) f[j]=1,cnt++;
		}
		if (cnt==n) continue;
		int s;
		for (j=2;j<=n;j++) {
			if (f[j]) continue;
			if (u==0) u++,s=j; else {
				if ((y[i]-y[1])*(j-s)==(y[j]-y[s])*(i-1)) u++;
			}
		}
		if (u+cnt==n) {
			cout << "Yes";
			return 0;
		}
	}
	int flag=1;
	for (i=4;i<=n;i++) {
		if ((y[3]-y[2])*(i-2)!=(y[i]-y[2])*(3-2)) flag=0;
	}
	if ((y[3]-y[2])*(1-2)==(y[1]-y[2])*(3-2)) flag=0;
	if (flag) cout << "Yes"; else cout << "No";
	return 0;
}

