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
int p[129];

int main() {
	int len,ans,i,cnt;
	scanf("%d",&len);
	scanf("%s",s+1);
	ans=cnt=0;
	for (i=1;i<=len;i++) {
		if (s[i]>='A'&&s[i]<='Z') {
			cnt=0;
			mem0(p);
		} else {
			if (p[s[i]]==0) {
				p[s[i]]=1;cnt++;
			}
		}
		ans=max(ans,cnt);
	}
	cout << ans;
	return 0;
}
