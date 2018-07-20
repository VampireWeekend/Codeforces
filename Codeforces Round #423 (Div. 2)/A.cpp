#include <cstdio>
#include <iostream>
#include <vector>
#include <string.h>
#include <map>
#include <algorithm>
#include <set>
#include <math.h>
#include <cmath>
#include <queue>
using namespace std;
typedef long long ll;
const int maxn=200005;

int main() {
	int n,a,b,i,x;
	scanf("%d%d%d",&n,&a,&b);
	int ans=0;
	int nowa=a;
	int nowb=2*b;
	int nowc=b;
	for (i=1;i<=n;i++) {
		scanf("%d",&x);
		if (x==1) {
			if (nowa>0) nowa--; else 
			    if (nowb>0&&nowc>0) nowc--,nowb--;
			        else if (nowb>0) nowb--;
			          else ans++;
		} else {
			if (nowc>0) nowc--,nowb-=2; else ans+=2;
		}
	}
	printf("%d",ans);
	return 0;
}
