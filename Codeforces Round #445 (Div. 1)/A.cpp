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
const int maxn=200005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int a[maxn],b[maxn];

int main() {
	int n,i,ans=1;
	mem0(b);b[0]=1;
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		
			if (!b[a[i]]) ans++,b[i]=1; else b[a[i]]=0,b[i]=1;
	}
	cout << ans;
	return 0;
}
