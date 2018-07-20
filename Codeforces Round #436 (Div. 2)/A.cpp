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
int a[maxn];

int main() {
	int n,i,x;
	cin >> n;
	int k,l;
	mem0(a);
	for (i=1;i<=n;i++) {
		cin >> x;
		a[x]++;
	}
	k=l=-1;
	int sum=0;
	for (i=1;i<=100;i++) {
		if (a[i]) {
			sum++;
			if (k==-1) k=i; else l=i;
		}
	}
	if (sum==2) {
		if (a[k]==a[l]) cout << "YES" << "\n" << k << ' ' << l; else cout << "NO";
	} else cout << "NO";
	return 0;
}
