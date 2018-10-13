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
const int maxn=1000005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
char s[maxn],t[maxn];

int main() {
	int n,a,b,ans=0;
	a=b=0;
	scanf("%d",&n);
	scanf("%s%s",s+1,t+1);
	for (int i=1;i<=n;i++) {
		if (s[i]!=t[i]&&s[i+1]!=t[i+1]&&s[i]!=s[i+1]) {
			i++;ans++;
		} else if (s[i]!=t[i]) {
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
