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
const int inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);

int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	if (n==1) {
		printf("0 0");
		return 0;
	}
	if (k==0||k==n) printf("0"); else printf("1");
	printf(" ");
	if (k>=(n+2)/3) printf("%d",n-k); else printf("%d",2*k);
	return 0;
}

