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
char s[maxn];

int main() {
	scanf("%s",s+1);
	int len=strlen(s+1),i,d=0;
	for (i=1;i<=len/2;i++) {
		if (s[i]!=s[len-i+1]) d++;
	}
	if ((d==1&&len%2==0)||(d<=1&&len%2==1)) cout << "Yes"; else cout << "No";
	return 0;
}

