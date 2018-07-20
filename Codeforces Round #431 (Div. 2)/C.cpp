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
const int maxn=505,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int f[maxn];

int main() {
	int n,k,i,j;
	f[2]=1;
	char c;
	for (i=3;i<=500;i++) {
		f[i]=f[i-1]+i-1;
	}
	scanf("%d",&k);
	if (k==0) {
		printf("a");
		return 0;
	}
	c='a';
	for (i=500;i>=2;i--) {
		if (k>=f[i]) {
			while (k>=f[i]&&c<='z') {
				k-=f[i];
				for (j=1;j<=i;j++) printf("%c",c);
				c=(char)(c+1);
			}
		}
	}
	return 0;
}

