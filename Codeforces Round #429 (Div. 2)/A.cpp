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
char s[1005];

int main() {
	int n,k,i,ans=0;
	char c;
	scanf("%d%d",&n,&k);
	scanf("%s",s);
	int len=strlen(s);
	map<char,int> mp;
	for (i=0;i<len;i++) {
		if (!mp[s[i]]) ans++;
		mp[s[i]]++;
	}
	for (c='a';c<='z';c++) {
		if (mp[c]>k) {
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	return 0;
}

