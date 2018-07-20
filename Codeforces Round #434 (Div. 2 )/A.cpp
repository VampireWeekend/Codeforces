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
typedef double db;
const int maxn=100005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);

int main() {
	ll n,k,ans=1,j,c5,c2,cnt;
	int i;
	cin >> n >> k;
	c5=c2=cnt=0;
	ll p=n;
	while (p%10==0&&cnt+c5<k) {
		cnt++;
		p/=10;
	}
	while (p%5==0&&cnt+c5<k) {
		c5++;
		p/=5;
	}
	while (p%2==0&&cnt+c5+c2<k) {
		c2++;
		p/=2;
	}
	ans=n;
	for (i=1;i<=c5;i++) ans*=2;
	for (i=1;i<=c2;i++) ans*=5;
	for (i=cnt+c5+c2+1;i<=k;i++) ans*=10;
	cout << ans << endl;
	return 0;
}

