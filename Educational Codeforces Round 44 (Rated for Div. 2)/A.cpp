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
int a[maxn];

int main() {
	int n,x,sum=0,ans=0;
	scanf("%d",&n);
	for (int i=1;i<=n/2;i++) {
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n/2+1);
	for (int i=1;i<=n/2;i++) {
		sum+=abs(i*2-1-a[i]);
	}
	for (int i=1;i<=n/2;i++) {
		ans+=abs(i*2-a[i]);
	}
	ans=min(ans,sum);
	cout << ans;
	return 0;
}
