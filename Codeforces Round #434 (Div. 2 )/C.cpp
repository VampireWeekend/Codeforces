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
typedef double db;
const int maxn=3005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
char s[maxn];

int main() {
	map<char,int> mp;
	mp['a']=mp['e']=mp['i']=mp['o']=mp['u']=1;
	int cnt=0,i,len;
	scanf("%s",s+1);
	len=strlen(s+1);
	for (i=1;i<=len;i++) {
		if (mp[s[i]]==0) cnt++; else cnt=0;
		if (cnt==3) {
			if (!(s[i]==s[i-1]&&s[i-1]==s[i-2])) {
				printf(" ");
			    cnt=1;
			} else cnt--;
		}
		printf("%c",s[i]);
	}
	return 0;
}

