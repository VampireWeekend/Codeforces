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
const int maxn=1005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);
char s[maxn];

int main() {
	int n,flag=0;
	scanf("%s",s);
	char a,b;
	map<char,int> mp;
	mp['^']=1;
	mp['>']=2;
	mp['v']=3;
	mp['<']=4;
	a=mp[s[0]];
	scanf("%s",s);
	b=mp[s[0]];
	scanf("%d",&n);
	int p=b-a;
	while (p<0) p+=4;
	if (p==n%4&&n%4!=2&&n%4!=0) cout << "cw"; else 
	if (n%4==2||n%4==0) cout << "undefined"; else cout << "ccw";
	return 0;
}

