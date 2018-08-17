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
const int inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);

int main() {
	ll n,k,ans;
	cin >> n >> k;
	if (n*2-1<k||k==1||n==1||k==2) ans=0; else {
		ll mid=k/2,umid=k-mid;
		if (mid==umid) mid--,umid++;
		ans=min(mid,n-umid+1);
	}
	cout << ans << endl;
	return 0;
}
