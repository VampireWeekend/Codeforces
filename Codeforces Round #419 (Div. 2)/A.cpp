#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
int n,m;
char s[5];

bool check(int n,int m) {
	if (n%10==m/10&&n/10==m%10) return true; else return false;
}

int main() {
	scanf("%d:%d",&n,&m);
	int ans=0;
	while (1) {
		if (check(n,m)) {
			cout << ans;
			return 0;
		}
		ans++;
		m++;
		if (m==60) {
			m=0;
			n++;
			if (n==24) n=0;
		}
	}
}
