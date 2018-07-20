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
const int maxn=5005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f,mod=998244353;   
const ld pi=acos(-1.0L);
ll C[maxn][maxn];

int main() {
	ll a,b,c,i,j;
	cin >> a >> b >> c;
	C[0][0]=1;
	for (i=1;i<=5000;i++) {
		C[i][0]=1;
		for (j=1;j<=i;j++) {
			C[i][j]=C[i-1][j]+C[i-1][j-1];
			C[i][j]%=mod;
		}
	}
	if (a<b) swap(a,b);
	if (a<c) swap(a,c);
	if (b<c) swap(b,c);
	ll na,nb,nc,l;
	l=1;
	na=nb=nc=1;
	for (i=a;i>=a-b+1;i--) {
		l*=i;
		l%=mod;
		na+=l*C[b][a-i+1];na%=mod;
//		cout << na << endl;
	}
	l=1; 
	for (i=a;i>=a-c+1;i--) {
		l*=i;
		l%=mod;
		nb+=l*C[c][a-i+1];nb%=mod;
	}
	l=1;
	for (i=b;i>=b-c+1;i--) {
		l*=i;
		l%=mod;
		nc+=l*C[c][b-i+1];nc%=mod;
	}
	ll ans=(((na*nb)%mod)*nc)%mod;
	printf("%I64d\n",ans);
	return 0;
}
