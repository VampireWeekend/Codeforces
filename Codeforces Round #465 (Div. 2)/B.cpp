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
	int n,i,len,st,ans=0,x,y;
	scanf("%d",&len);
	scanf("%s",s);
	if (s[0]=='U') st=1,x=0,y=1; else st=-1,x=1,y=0;
	for (i=1;i<len;i++) {
		if (s[i]=='U') y++; else x++;
		if (st==1&&x>y) ans++,st=-1; else
			if (st==-1&&x<y) ans++,st=1;
	}
	printf("%d\n",ans);
	return 0;
}
