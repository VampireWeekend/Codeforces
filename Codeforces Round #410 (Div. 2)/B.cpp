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
const int maxn=55,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
char s[maxn][maxn];

int main() {
	int n,i,j,k,len,st,sum,ans;
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		scanf("%s",s[i]);
	}
	len=strlen(s[1]);
	ans=inf;
	int flag;
	for (st=0;st<len;st++) {
		sum=st;
		for (i=2;i<=n;i++) {
			for (j=0;j<len;j++) {
				flag=1;
				for (k=0;k<len;k++) {
					if (s[i][(j+k)%len]!=s[1][(st+k)%len]) {
						flag=0;break;
					}
				}
				if (flag) {
					sum+=j;
					break;
				}
			}
			if (!flag) break;
		}
		if (flag) ans=min(ans,sum);
	}
	if (ans==inf) cout << -1; else cout << ans;
	return 0;
}

