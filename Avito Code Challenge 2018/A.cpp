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
#define pb push_back 
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
	scanf("%s",s+1);
	int len=strlen(s+1);
	int i,j,flag=1;
	for (i=1;i<=len;i++) {
		if (s[i]!=s[len-i+1]) flag=0;
	}
	if (!flag) cout << len; else {
		int cnt=0;
		for (i=2;i<=len;i++) if (s[i]!=s[1]) cnt++;
		if (cnt) cout << len-1; else cout << 0;
	}
	return 0;
}
