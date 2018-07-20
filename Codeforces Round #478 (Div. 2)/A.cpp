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
char sh[maxn][maxn];
string s[maxn];
int a[maxn];

int main() {
	int n,i,j;
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		scanf("%s",sh[i]+1);
		int len=strlen(sh[i]+1);
		for (j=1;j<=len;j++) {
			a[sh[i][j]-'a']=i;
		}
		s[i]="";
		for (j=0;j<26;j++) {
			if (a[j]==i) s[i]=s[i]+(char)('a'+j);
		}
	}
	sort(s+1,s+n+1);
	int ans=unique(s+1,s+n+1)-s-1;
	printf("%d\n",ans);
	return 0;
}
