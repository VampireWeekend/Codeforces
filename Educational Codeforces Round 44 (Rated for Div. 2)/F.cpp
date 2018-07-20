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
#define pb push_back 
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=200005;
const ll inf=0x3f3f3f3f,mod=1e9+7;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
ll hash[maxn][26],fac[maxn];
char s[maxn];
vector<int> v[26];

int main() {
	int n,m,i,j,x,y,z;
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	fac[0]=1;
	for (i=1;i<=n;i++) {
		fac[i]=(fac[i-1]*inf)%mod;
		for (j=0;j<26;j++) {
			hash[i][j]=(hash[i-1][j]*inf+(s[i]==(char)('a'+j)))%mod;
		}
		v[s[i]-'a'].pb(i);
	}
	for (j=0;j<26;j++) v[j].pb(n+1); 
	for (i=1;i<=m;i++) {
		scanf("%d%d%d",&x,&y,&z);
		int flag=1;
		for (j=0;j<26;j++) {
			int pos=lower_bound(v[j].begin(),v[j].end(),x)-v[j].begin();
			pos=v[j][pos];
			if (pos>=z+x) continue;
			int dual=s[pos-x+y]-'a';
			ll h1=(((hash[z+x-1][j]-hash[x-1][j]*fac[z])%mod)+mod)%mod;
			ll h2=(((hash[z+y-1][dual]-hash[y-1][dual]*fac[z])%mod)+mod)%mod;
			if (h1!=h2) {
				flag=0;break;
			}
		}
		if (flag) printf("YES\n"); else printf("NO\n");
	}
	return 0;
}
