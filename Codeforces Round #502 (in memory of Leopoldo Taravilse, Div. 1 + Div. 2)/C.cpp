#include <cstdio>
using namespace std;
const int maxn=100005,inf=0x3f3f3f3f;
int a[maxn];

int main() {
	int n,ans=inf,len=-1;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		int now=(n-1)/i+1+i;
//		cout << now << endl;
		if (now<ans) {
			ans=now;len=i;
		}
	}
	int cnt=n;
	for (int i=1;i<=n;i+=len) {
		if (i+len>n) {
			for (int j=i;j<=n;j++) a[j]=1+j-i;
		} else {
			for (int j=i;j<=i+len-1;j++) a[j]=cnt-len+j-i+1;
			cnt-=len;
		}
	}
	for (int i=1;i<=n;i++) printf("%d ",a[i]);
	return 0;
}
