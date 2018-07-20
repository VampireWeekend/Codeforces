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
char s[maxn];

int main() {
	int n,i;
	cin >> n;
	scanf("%s",s+1);
	int cnt=0,sum=0;
	for (i=1;i<=n;i++) {
		if (s[i]=='?') {
			if (s[i-1]!=s[i+1]&&s[i-1]!='?'&&s[i+1]!='?'&&i!=1&&i!=n) continue;
			cnt++;
		}
		if (i>1&&s[i]!='?'&&s[i-1]!='?')
			if (s[i]==s[i-1]) {
				cout << "No";return 0;
			}
	}
	if (cnt==0) cout << "No"; else cout << "Yes";
	return 0;
}
