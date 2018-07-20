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
	int n;
	scanf("%d",&n);
	scanf("%s",s+1);
	int flag=1;
	for (int i=1;i<=n;i++) {
		if (s[i]=='1'){
			if ((s[i-1]=='1'&&i!=1)||(s[i+1]=='1'&&i!=n)) flag=0;
		} else {
			if ((s[i-1]=='0'||i==1)&&(s[i+1]=='0'||i==n)) flag=0;
		}
	}
	if (flag) cout << "yes"; else cout << "no";
	return 0;
}
