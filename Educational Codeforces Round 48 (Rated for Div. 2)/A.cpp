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

int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	int now=0;
	for (int i=1;i<=n;i++) {
		scanf("%d",&x);
		x+=now;
		int ans=x/m;
		x-=ans*m;
		if (x>0) ans++;
		now=x;
		printf("%d\n",ans);
	}
	return 0;
}
