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
#include <assert.h>
#define pb push_back 
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef pair<int,int> pp;
const int maxn=100005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
int cnt[maxn];
char a[maxn],b[maxn];

int main() {
	int n;
	scanf("%d",&n);
	scanf("%s%s",a+1,b+1);
	ll ans=0;
	for (int i=1;i<=n;i++) {
		int now=(a[i]-'0')*2+b[i]-'0';
		if (now==3) {
			ans+=cnt[0];
		} else if (a[i]=='1'){
			ans+=cnt[0]+cnt[1];
		} else if (b[i]=='1') {
			ans+=cnt[2];
		} else {
			ans+=cnt[2]+cnt[3];
		}
		cnt[now]++;
	}
	printf("%lld\n",ans);
	return 0;
}
