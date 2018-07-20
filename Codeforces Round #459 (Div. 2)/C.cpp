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
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
char s[maxn];

int main() {
	scanf("%s",s+1);
	int n,i,j,a,b,c;
	ll ans=0;
	n=strlen(s+1);
	for (i=1;i<n;i++) {
		a=b=c=0;
		for (j=i;j<=n;j++) {
			if (s[j]==')') b++; else
				if (s[j]=='(') a++; else c++;
			if (b+c>a&&c>0) a++,c--;
			if (b>c+a) 
				break;
			if ((j-i)%2) 
				if (a<=b+c&&s[j]!='(') ans++;
		}
//		cout << ans << endl;
	}
	printf("%I64d\n",ans);
	return 0;
}
