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
const int maxn=1005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int cnt[maxn];

int main() {
	ll n,i,p=0,tot=0,o,k;
	scanf("%I64d%I64d",&k,&n);
	mem0(cnt);
	while (k) {
		cnt[p+500]+=k%2;
		if (k%2) tot++;
		k/=2;
		p++;
	}
	if (tot>n) {
		printf("No\n");
		return 0;
	} else printf("Yes\n");
	for (i=p+500;i>=0;i--) {
		if (tot==n) break;
		while (tot<n&&cnt[i]) {
			cnt[i]--;tot++;cnt[i-1]+=2;
		}
	}
	for (i=p+500;i>=0;i--) {
		for (int j=1;j<=cnt[i];j++) printf("%d ",i-500);
	}
	return 0;
}
