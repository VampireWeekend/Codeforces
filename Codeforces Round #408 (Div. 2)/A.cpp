#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn=105;
int n,m,k,i,a[maxn],min1,aa,min2;

int main(){
	min2=1<<30;
	cin >> n >> m >> k;
	min1=-1<<30;
	for (i=1;i<=m-1;i++) {
		cin >> aa;
		if (aa!=0&&aa<=k) min1=i;
	}
	cin >> aa;
	for (i=m+1;i<=n;i++) {
		cin >> aa;
		if (aa!=0&&aa<=k) {
			min2=i;
			break;
		}
	}
	cout << min(m-min1,min2-m)*10 << endl;
	return 0;
}
