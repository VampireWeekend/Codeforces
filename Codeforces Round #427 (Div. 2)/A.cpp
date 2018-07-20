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
const int maxn=100005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);
char s[maxn];
int a[105];

int main() {
	int n,k,len,i,j,ans=0,sum;
	scanf("%d",&k);
	scanf("%s",s);
	len=strlen(s);
	sum=k;
	mem0(a);
	for (i=0;i<len;i++) {
		a[s[i]-'0']++;
		sum-=s[i]-'0';
	}
	for (i=0;i<=9;i++) {
		for (j=1;j<=a[i];j++) {
			if (sum>0) sum-=9-i,ans++; else break;
		}
		if (sum<=0) break;
	}
	cout << ans;
	return 0;
}

