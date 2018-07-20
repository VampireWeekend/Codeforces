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
const int maxn=100005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);

int main() {
	int x,a,b,cnt=0;
	cin >> x >> a >> b;
	while (!(a%10==7||b%10==7)) {
		cnt++;
		b-=x;
		if (b<0) {
			b+=60;a--;
			if (a<0) {
				a+=24;
			}
		}
	}
	cout << cnt;
	return 0;
}
