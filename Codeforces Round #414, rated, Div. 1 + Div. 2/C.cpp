#include <cstdio>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn=300005;
char a[maxn],b[maxn];

bool cmp(char a,char b) {
	return a<b;
}

int main() {
	int i;
	scanf("%s",a);
	scanf("%s",b);
	int len=strlen(a);
	sort(a,a+len,cmp);
	sort(b,b+len,cmp);
if (a[1]<=b[len-1]||len%2==1) {
	for (i=1;i<=len;i++) {
		if (i%2==1) {
			printf("%c",a[i/2]);
		} else {
			printf("%c",b[len-i/2]);
		}
	}
}
else {
	for (i=1;i<=len;i++) {
		if (i%2==1) {
			printf("%c",b[len-(i+1)/2]);
		} else {
			printf("%c",a[i/2-1]);
		}
	}
}
	return 0;
}
