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
const int maxn=150005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
ll a[maxn];
bool b[maxn];
map<ll,int> mp;

int main() {
	int n,i,j;
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		scanf("%I64d",&a[i]);
		b[i]=1;
		while (mp[a[i]]!=0) {
			int p=mp[a[i]];
			mp[a[i]]=0;
			b[p]=0;
			a[i]*=2;
		}
		mp[a[i]]=i;
	}
	int m=0;
	for (i=1;i<=n;i++) if (b[i]) m++;
	printf("%d\n",m);
	for (i=1;i<=n;i++) if (b[i]) printf("%I64d ",a[i]);
	return 0;
}
