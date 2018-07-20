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
const int maxn=2005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int a[maxn],b[maxn];

int main() {
	map<int,int> mp;
	int n,i,j,cnt=0;
	scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%d",&a[i]),mp[a[i]]=1;
	for (i=1;i<=n;i++) scanf("%d",&b[i]),mp[b[i]]=1;
	for (i=1;i<=n;i++) {
		for (j=1;j<=n;j++) {
			if (mp[a[i]^b[j]]) cnt++;
		}
	}
	if (cnt%2==0) cout << "Karen"; else cout << "Koyomi";
	return 0;
}
