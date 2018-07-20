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
const int maxn=105,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L); 
int a[maxn];

int main() {
    int n,i,k,sum=0,p=0;
    scanf("%d%d",&n,&k);
    for (i=1;i<=n;i++) {
    	scanf("%d",&a[i]);
    }
    for (i=1;i<=n;i++) {
    	sum+=a[i];
    	if (sum>=8) p+=8,sum-=8; else {
    		p+=sum;
    		sum=0;
    	}
    	if (p>=k) break;
    }
    if (i!=n+1) printf("%d",i); else printf("-1");
	return 0;
}

