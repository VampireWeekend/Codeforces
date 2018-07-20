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
map<int,int> mp[maxn];

int lowbit(int x) {
	return x&(-x);
}

int main() {
	int n,m,i,j,x,y,z;
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;i++) {
		int p=0;
		scanf("%d%d%d",&x,&y,&z);
		if (mp[x].size()==0) p=1; else {
			
		}
	}
	return 0;
}
