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
ll a[maxn],b[maxn],c[maxn];
string s[maxn];
map<string,int> mp;

int main() {
	ios::sync_with_stdio(false);
	meminf(a);
	int n,k,m,i,j,x,y;
	cin >> n >> k >> m; 
	for (i=1;i<=n;i++) {
		cin >> s[i];
	}
	for (i=1;i<=n;i++) {
		cin >> b[i];
	}
	for (i=1;i<=k;i++) {
		cin >> x;
		for (j=1;j<=x;j++) {
			cin >> y;
			a[i]=min(a[i],b[y]);
			mp[s[y]]=i;
		}
	}
	ll sum=0;
	string t;
	for (i=1;i<=m;i++) {
		cin >> t;
		sum+=a[mp[t]];
	}
	cout << sum << endl;
	return 0;
}
