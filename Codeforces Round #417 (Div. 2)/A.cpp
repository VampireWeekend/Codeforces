#include <cstdio>
#include <string.h>
#include <iostream>
using namespace std;
const int maxn=505;
int l[5],r[5],s[5],p[5];

int main() {
	int n=0,i;
	for (i=1;i<=4;i++) {
		scanf("%d%d%d%d",&l[i],&s[i],&r[i],&p[i]);
	}
	for (i=1;i<=4;i++) {
		if (p[i]==1) {
			if (l[i]==1||s[i]==1||r[i]==1) n=1;
		}
	}
	if (p[1]&&(l[2]||s[3]||r[4])) n=1;
	if (p[2]&&(l[3]||s[4]||r[1])) n=1;
	if (p[3]&&(l[4]||s[1]||r[2])) n=1;
	if (p[4]&&(l[1]||s[2]||r[3])) n=1;
	if (n) cout << "YES"; else cout << "NO";
	return 0;
}
