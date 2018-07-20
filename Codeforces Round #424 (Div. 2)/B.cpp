#include <string.h> 
#include <map>
#include <cstdio>
#include <iostream>
#include <math.h>
#include <cmath>
#define mem(a) memset(a,0,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
char a[1005],b[1005],c[1005];

int main() {
	map<char,char> my;
	int l='A'-'a',i;
	scanf("%s",a);
	scanf("%s",b);
	for (i=0;i<26;i++) {
		my[a[i]]=b[i];
		my[(char)(a[i]+l)]=(char)(b[i]+l);
	}
	scanf("%s",c);
	int len=strlen(c);
	for (i=0;i<len;i++) {
		if ((c[i]>='a'&&c[i]<='z')||(c[i]>='A'&&c[i]<='Z')) {
			char r=my[c[i]];
		cout << r;
		} else cout << c[i];
	}
	return 0;
}
