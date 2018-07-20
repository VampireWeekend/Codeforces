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
const int maxn=200005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
int a[maxn],b[maxn];

int main() {
	int n,k,i,cnt=0;
	scanf("%d%d",&n,&k);
	for (i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	int size=1,l;
	a[0]=a[1]-1;
	for (i=1;i<=n;i++) {
		if (a[i]==a[i-1]) size++; else
		if (abs(a[i]-a[i-1])>k) {
			cnt+=size;size=1;
		} else size=1;
	}
	cnt+=size;
	printf("%d\n",cnt);
	return 0;
}
