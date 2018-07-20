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
const int maxn=300005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
ll a[maxn];

int main() {
	int n,i,j;
	ll ans=0;
	priority_queue<ll,vector<ll>,greater<ll> > pq;
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	for (i=1;i<=n;i++) {
		if (!pq.empty()) {
			if (pq.top()<a[i]) {
				ans+=a[i]-pq.top();
				pq.pop();
				pq.push(a[i]);
			}
		}
		pq.push(a[i]);
	}
	printf("%I64d\n",ans);
	return 0;
}
