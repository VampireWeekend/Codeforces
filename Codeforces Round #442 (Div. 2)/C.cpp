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
vector<int> v;

int main() {
	int n,i,m,l,r;
	scanf("%d",&n);
	if (n==2) {
		printf("3\n2 1 2\n");return 0;
	}
	for (i=2;i<=n;i+=2) v.push_back(i);
	for (i=1;i<=n;i+=2) v.push_back(i);
	for (i=2;i<=n;i+=2) v.push_back(i);
	m=v.size();
	printf("%d\n",m);
	for (i=0;i<m;i++) printf("%d ",v[i]);
	return 0;
}
