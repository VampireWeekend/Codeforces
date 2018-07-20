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
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
char s[maxn];

int main() {
	int n,m,i,j,l,r;
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	char a,b;
	for (i=1;i<=m;i++) {
		scanf("%d %d ",&l,&r);
		scanf("%c %c",&a,&b);
		for (j=l;j<=r;j++) {
			if (s[j]==a) s[j]=b;
		}
	}
	for (i=1;i<=n;i++) printf("%c",s[i]);
	return 0;
}
