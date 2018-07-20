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
const int maxn=1000005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int ans[maxn];

int main() {
	int n,a,b,x,y,flag=0,i,j;
	scanf("%d%d%d",&n,&x,&y);
	if (n%x==0||n%y==0) {
		if (n%x==0) a=n/x,b=0; else a=0,b=n/y;
		flag=1;
	} else
	for (i=1;i<=n/x;i++) {
		a=i;
		if ((n-a*x)%y==0) {
			b=(n-a*x)/y;
			flag=1;
			break;
		}
	}
	if (flag==0) {
		cout << -1;return 0;
	}
	n=0;int cnt=0;
	for (i=1;i<=a;i++) {
		for (j=2;j<=x;j++) {
			ans[++n]=cnt+j;
		}
		ans[++n]=cnt+1;
		cnt+=x;
	}
	for (i=1;i<=b;i++) {
		for (j=2;j<=y;j++) {
			ans[++n]=cnt+j;
		}
		ans[++n]=cnt+1;
		cnt+=y;
	}
	for (i=1;i<=n;i++) {
		printf("%d ",ans[i]);
	}
	return 0;
}
