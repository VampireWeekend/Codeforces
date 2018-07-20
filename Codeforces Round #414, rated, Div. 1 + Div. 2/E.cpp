#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[300005];

bool cmp(int a,int b) {
	return a>b;
}

int main() {
	int n,i;
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1,cmp);
	for (i=n;i>0;i--) {
		printf("%d ",a[(i+1)/2]);
	}
}
