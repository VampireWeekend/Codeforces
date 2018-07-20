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
const int maxn=105,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
char s[maxn],t[maxn];

int main() {
	int i,l,r,len;
	scanf("%s",s+1);
	scanf("%s",t+1);
	len=strlen(s+1);
	for (i=2;i<=len;i++) {
		if (s[i]>=t[1]) break;
	}
	int u=i-1;
	if (u>len) u=len;
	for (i=1;i<=u;i++) printf("%c",s[i]);
	printf("%c",t[1]);
	return 0;
}
