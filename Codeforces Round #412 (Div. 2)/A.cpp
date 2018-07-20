#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
const int maxn=1005;
int a[maxn],b[maxn],c[5000],d[5000];

int main() {
	int n,i;
	cin >> n;
	memset(c,0,sizeof(c));
	memset(d,0,sizeof(d));
	for (i=1;i<=n;i++) {
		cin >> a[i] >> b[i];
	}
	a[0]=b[0]=0;
	int flag1=0,flag2=0;
	for (i=1;i<=n;i++) {
	    if (a[i]!=b[i]) flag1=1;
		if (a[i]==a[i-1]) flag2=1;
	}
	if (flag1) cout << "rated"; else 
	    if (!flag2) cout << "unrated"; else cout << "maybe";
	return 0;
}
