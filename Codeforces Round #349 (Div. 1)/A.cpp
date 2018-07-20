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
string a[maxn*2];
string s;
bool dp[maxn][2];

int main() {
	cin >> s;
	int i,len=s.length(),m=0;
	mem0(dp);
	for (i=len-2;i>=5;i--) {
		if (len-i==2) {
			a[++m]=s.substr(i,2);
			dp[i][0]=1;
		} else if (len-i==3) {
			a[++m]=s.substr(i,3);
			dp[i][1]=1;
		} else if (len-i==4) {
			if (s.substr(i,2)!=s.substr(i+2,2)) {
				a[++m]=s.substr(i,2);
				dp[i][0]=1;
			}
		} else {
			if ((s.substr(i,2)!=s.substr(i+2,2)&&dp[i+2][0])||dp[i+2][1]) {
				a[++m]=s.substr(i,2);
				dp[i][0]=1;
			} 
			if ((s.substr(i,3)!=s.substr(i+3,3)&&dp[i+3][1])||dp[i+3][0]) {
				a[++m]=s.substr(i,3);
				dp[i][1]=1;
			} 
		}
//		cout << dp[i][0] << ' ' << dp[i][1] << endl;
	}
	sort(a+1,a+m+1);
	int ans=unique(a+1,a+m+1)-a-1;
	printf("%d\n",ans);
	for (i=1;i<=ans;i++) {
		cout << a[i] << endl;
	}
	return 0;
}
