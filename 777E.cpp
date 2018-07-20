//20:43
#include <cstdio>
#include <iostream>
using namespace std;
const int maxn=100001;
int n,i;
long long ans;
int max[maxn],a[maxn],b[maxn],h[maxn];
long long dp[maxn];

void qsort(int a[],int b[],int c[],int l,int r){
	int i=l;
	int j=r;
	int mid=a[(l+r)/2];
	while (i<=j) {
		while (a[i]>mid) i++;
		while (mid>a[j]) j--;
		if (i<j) {
			int z;
			z=a[i];a[i]=a[j];a[j]=z;
			z=b[i];a[i]=b[j];b[j]=z;
			z=c[i];a[i]=c[j];c[j]=z;
			i++;j--;
		}
	}
	if (i<r) qsort(a,b,c,i,r);
	if (l<j) qsort(a,b,c,l,j);
}

int find(int l,int r,int v) {
	if (l==r) return l;
	int mid=(l+r)/2;
	if (v>=a[mid]) return find(l,mid-1,v); else return find(mid+1,r,v);
}

int main() {
	cin >> n;
	for (i=1;i<=n;i++) cin >> a[i] >> b[i] >> h[i];
	qsort(b,a,h,1,n);
	ans=h[1];
	dp[1]=h[1];max[1]=h[1];
	for (i=2;i<=n;i++) {
		if (b[i]<a[1]) {
			
		}
	}
	cout << ans << endl;
	return 0;
}
