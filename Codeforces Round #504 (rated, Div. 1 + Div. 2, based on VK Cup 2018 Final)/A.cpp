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
#include <assert.h>
#define pb push_back 
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef pair<int,int> pp;
const int maxn=200005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
char s[maxn],t[maxn];

int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	scanf("%s%s",s+1,t+1);
	if (n>m+1) {
		printf("NO");return 0;
	}
	int flag=1,i=0;
	for (int j=1;j<=m;j++) {
	    i++;
		if (s[i]=='*') {
		    if (n==m+1) i++;
			while (n-i+1<m-j+1) j++;
		} else {
			if (s[i]!=t[j]) flag=0;
		}
//		cout << i << ' ' << j << endl;
	}
	if (flag&&i==n) printf("YES"); else printf("NO");
	return 0;
}
