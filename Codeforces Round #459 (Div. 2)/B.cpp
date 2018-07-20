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
const int maxn=10005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
map<string,string> mp;
string s,t;

int main() {
	int n,m,i;
	cin >> n >> m;
	for (i=1;i<=n;i++) {
		cin >> s >> t;
		t=t+";";
		mp[t]=s;
	}
	for (i=1;i<=m;i++) {
		cin >> s >> t;
		cout << s << ' ' << t << " #" << mp[t] << endl;
	}
	return 0;
}
