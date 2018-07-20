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
const int maxn=200005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
char s[maxn];

int main() {
	int i,j,k,n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	scanf("%s",s+1);
	s[0]='*';
	int p=1,sum=a+b;
	for (i=1;i<=n;i++) {
		if (s[i]=='*') continue;
		if (s[i-1]=='*') {
			if (a>b&&a) a--,p=1; else if (b) b--,p=-1; else break;
		} else {
			if (p==1&&b) b--; else if (p==-1&&a) a--;
			p*=-1;
		}
	}
	printf("%d\n",sum-a-b);
	return 0;
}
