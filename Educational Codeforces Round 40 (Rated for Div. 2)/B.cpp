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
const int maxn=1005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
char s[maxn];

int main() {
	int n,i,j,ans=-1;
	scanf("%d",&n);
	scanf("%s",s+1);
	for (i=1;i<=n/2;i++) {
		int flag=1;
		for (j=1;j<=i;j++) {
			if (s[j]!=s[j+i]) flag=0;
		}
		if (flag) ans=i;
	}
	if (ans==-1) ans=n; else ans=min(n-ans+1,n);
	cout << ans;
	return 0;
}
