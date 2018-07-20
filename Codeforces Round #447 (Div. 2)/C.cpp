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
#include <time.h>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=10005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int a[maxn];

ll gcd(ll x,ll y) {
	if (x<y) swap(x,y);
	ll z;
	while (y) {
		z=x%y;
		x=y;
		y=z;
	}
	return x;
}

int main() {
	int t;
	cin >> t;
	srand((unsigned)time(NULL));
	while (t--) {
		int n=rand()%11+5;
		int i,j,p,q;
		cout << n << endl;
		for (i=1;i<=n;i++) {
			a[i]=rand()%50+1;
			printf("%d ",a[i]);
		}
		cout << '\n';
		q=n;
		for (i=1;i<=q;i++) {
			p=a[i];
			for (j=i+1;j<=q;j++) {
				p=gcd(p,a[j]);
				a[++n]=p;
			}
		}
		sort(a+1,a+n+1);
		n=unique(a+1,a+n+1)-a-1;
		cout << n << endl;
		for (i=1;i<=n;i++) {
			printf("%d ",a[i]);
		}
		cout << '\n';
	}
	return 0;
}
