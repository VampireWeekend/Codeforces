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
const int maxn=300005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
ll a[maxn][2],pre[maxn],psum[maxn],upsum[maxn],downsum[maxn];

int main() {
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf("%I64d",&a[i][0]);
	}
	for (int i=1;i<=n;i++) {
		scanf("%I64d",&a[i][1]);
	}
	for (int i=n;i>=1;i--) {
		psum[i]=psum[i+1]+a[i][0]+a[i][1];
	}
	ll ans=-inf;
	ll m=n,sum=0;
	for (int i=n;i>=1;i--) {
		upsum[i]=upsum[i+1]+(i-1)*a[i][0]+(2*n-i)*a[i][1];
	}
	ans=max(sum,upsum[1]);
	
	m=0,sum=0;
	for (int i=1;i<=n;i++) {
		if (i%2==1) {
			sum+=m*a[i][0];
			m++;
			sum+=m*a[i][1];
			m++;
		} else {
			sum+=m*a[i][1];
			m++;
			sum+=m*a[i][0];
			m++;
		}
		pre[i]=sum;
	}
	ans=max(sum,ans);
	
	m=1,sum=0;
	for (int i=n;i>1;i--) {
		downsum[i]=downsum[i+1]+(i-1)*a[i][1]+(2*n-i)*a[i][0];
	}
	downsum[1]=downsum[2]+a[1][1];
	ans=max(downsum[1],ans);
	
	sum=0;
	for (int i=1;i<n;i++) {
	    ll get;
		if (i%2==1) {
			get=pre[i]+downsum[i+1]+psum[i+1]*i;
		} else {
			get=pre[i]+upsum[i+1]+psum[i+1]*i;
		}
		ans=max(ans,get);
//		cout << get << endl;
	}
	
	printf("%I64d\n",ans);
	return 0;
}