#include <cstdio>
#include <iostream>
#include <string.h>
#include <string> 
#include <map>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=100005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L); 
char a[maxn]; 

int main() {
	char c;
	map<char,int> mp;
	scanf("%s",a);
	int len=strlen(a);
	int i,k,ans;
	cin >> k;
	if (k>len) cout << "impossible"; else {
		for (i=0;i<len;i++) {
			mp[a[i]]++;
		}
		ans=0;
		for (c='a';c<='z';c++) {
			if (mp[c]) ans++;
		}
		ans=max(k-ans,0);
		cout << ans;
	}
	return 0;
}

