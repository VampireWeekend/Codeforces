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
#include <bitset>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=1000005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);
char s[maxn];
int first[34],last[35];

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
    int n,k,i,j,ans,len;
	scanf("%d%d",&n,&k);
	ans=0;
	scanf("%s",s);
	len=strlen(s);
	memset(first,-1,sizeof(first));
	for (i=0;i<len;i++) {
		if (first[s[i]-'A']==-1) first[s[i]-'A']=i;
		last[s[i]-'A']=i;
	}
	ans=j=0;
	for (i=0;i<len;i++) {
		if (first[s[i]-'A']==i) j++;
		ans=max(ans,j);
		if (last[s[i]-'A']==i) j--;
	}
	if (ans<=k) cout << "NO"; else cout << "YES";
	return 0;
}

