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
const int maxn=1005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);

int main() {
	int n,k,i,j;
	scanf("%d%d",&n,&k);
	if (k%2==0) {
		printf("YES\n");
		int p=k/2;
		for (i=1;i<=4;i++) {
			k=p;
			for (j=1;j<=n;j++) {
				if ((i==2||i==3)&&j!=1&&j!=n) {
					if (k) printf("#"),k--; else printf("."); 
				} else printf(".");
			}
			cout << '\n';
		}
	} else {
		printf("YES\n");
		int p=k;
		for (i=1;i<=4;i++) {
			if (i==2) k=p/2; else k=p/2+1;
			for (j=1;j<=n;j++) {
				if ((i==2||i==3)&&j!=1&&j!=n) {
					if (j*2==n+1&&) printf("."); else
					if (k) printf("#"),k--; else 
						printf("."); 
				} else 
					printf(".");
			}
			cout << '\n';
		}
	}
	return 0;
}
