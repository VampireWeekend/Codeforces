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
	int x,y;
	cin >> x >> y;
	if (y==0) {
		cout << "No";
		return 0;
	} 
	if (y==1) {
		if (x==0) cout << "Yes"; else cout << "No";
		return 0;
	}
	if (x>=y-1) {
		if ((x+1-y)%2==0) cout << "Yes"; else cout << "No";
	} else cout << "No";
	return 0;
}
