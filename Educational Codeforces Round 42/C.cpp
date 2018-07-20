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
const int inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);

int main() {
	int n,i,ans=-1,j;
	scanf("%d",&n);
	int y=n,c=0,l=n;
	while (l) {
		l/=10;
		c++;
	}
	for (i=1;i<(1<<c);i++) {
		int x=n,sum=0,cnt=0,flag=1,last=-1,p=1;
		for (j=0;j<c;j++) {
			if ((i>>j)%2) sum+=(x%10)*p,cnt++,last=x%10,p*=10;
			x/=10;
		}
		if (last==0) continue;
		p=(int)sqrt(sum);
		if (p*p==sum||(p+1)*(p+1)==sum||(p-1)*(p-1)==sum) 
			ans=max(ans,cnt);
	}
	if (ans!=-1) ans=c-ans;
	printf("%d\n",ans);
	return 0;
}
