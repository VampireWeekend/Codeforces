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
const int inf=0x3f3f3f3f;  
const ll maxn=35,llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int a[maxn],b[maxn],son[maxn];
bool f[maxn];
int n,cnt=0;

bool dfs(int now,int size,int son) {
	if (now>n) return true;
	if (size==a[now]&&son>=2)
		if (dfs(now+1,1,0)) return true; else return false;
	int i,last=-1;
	for (i=now-1;i>=1;i--) {
		if (size+a[i]<=a[now]&&f[i]==0&&last!=a[i]) {
			f[i]=1;last=a[i];
			if (dfs(now,size+a[i],son+1)) return true;
			f[i]=0;
		}
	}
	return false;
}

int main() {
	int i,cnt=0;
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		if (a[i]==1) cnt++;
	}
	sort(a+1,a+n+1);
	mem0(f);
	if (a[n]!=n||cnt<(n+1)/2) printf("NO"); else
	if (dfs(cnt+1,1,0)) printf("YES"); else printf("NO");
	return 0;
}
