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
const int maxn=,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);


int main() {
	int a,b,c,d;
	int n,sum,nsum;
	int ans=1;
	scanf("%d",&n);
	scanf("%d%d%d%d",&a,&b,&c,&d);
	sum=a+b+c+d;
	for (int i=2;i<=n;i++) {
		scanf("%d%d%d%d",&a,&b,&c,&d);
		nsum=a+b+c+d;
		if (nsum>sum) ans++;
	}
	printf("%d\n",ans);
	return 0;
}
