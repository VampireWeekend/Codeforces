#include <cstdio>
#include <iostream>
using namespace std;
const int maxn=100005;

int main() {
	int n,i,a,b,c,ans=0,x;
	scanf("%d%d%d",&a,&b,&c);
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		scanf("%d",&x);
		if (x>=b+1&&x<=c-1) ans++;
	}
	cout << ans;
	return 0;
}
