#include <cstdio>
#include <iostream>
#include <string.h>
#include <string> 
#include <map>
#include <queue>
#include <deque>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>
#include <iomanip>
#define pb push_back 
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=105,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
char s[maxn][maxn];

struct node {
	char ch;
	int num;
};
node a[5];

bool cmp(node a,node b) {
	return a.num>b.num;
}

void fill1(int i,int j) {
	s[i][j]=a[1].ch;s[i][j+1]=a[2].ch;
	s[i+1][j]=a[3].ch;s[i+1][j+1]=a[4].ch;
	s[i+2][j]=a[3].ch;s[i+2][j+1]=a[4].ch;
	if (j==47) {
		for (int k=1;k<=49;k++) s[i+2][k]=a[2].ch;
		s[i+1][49]=s[i][49]=a[2].ch;
	}
}

void fill2(int i,int j) {
	s[i][j]=a[1].ch;s[i][j+1]=a[2].ch;
	s[i+1][j]=a[3].ch;s[i+1][j+1]=a[4].ch;
	s[i+2][j]=s[i+2][j+1]=a[4].ch;
}

void fill3(int i,int j) {
	s[i][j]=a[1].ch;s[i][j+1]=a[2].ch;
	s[i+1][j]=s[i+1][j+1]=a[4].ch;
	s[i+2][j]=s[i+2][j+1]=a[4].ch;
}

void fill4(int i,int j) {
	s[i][j]=a[1].ch;s[i][j+1]=a[4].ch;
	s[i+1][j]=s[i+1][j+1]=a[4].ch;
	s[i+2][j]=s[i+2][j+1]=a[4].ch;
}

int main() {
	int i,j;
	scanf("%d%d%d%d",&a[1].num,&a[2].num,&a[3].num,&a[4].num);
	a[1].ch='A';a[2].ch='B';a[3].ch='C';a[4].ch='D';
	sort(a+1,a+5,cmp);
	mem0(s);
	for (i=1;i<=50;i++) s[i][50]=a[4].ch;
//	for (i=1;i<=50;i+=3) {
		for (j=1;j<=50;j++) s[1][j]=a[4].ch;
//	}
	int n,m;n=2;m=1;
	while (a[4].num) {
		for (i=1;i<=4;i++) a[i].num--;
		fill1(n,m);
		m+=2;
		if (m>48) {
			m=1,n+=4;
		}
	}
	if (m==1) { 
		s[n-3][49]=a[4].ch;
		for (j=1;j<=49;j++) s[n-1][j]=s[n-2][j]=s[n-3][j];
	}
/*	 else for (j=1;j<=m-1;j++) {
		s[n+2][j]=s[n+1][j];
	}*/
	while (a[3].num) {
		for (i=1;i<=3;i++) a[i].num--;
		fill2(n,m);
		m+=2;if (m>48) m=1,n+=3;
	}
	while (a[2].num) {
		for (i=1;i<=2;i++) a[i].num--;
		fill3(n,m);
		m+=2;if (m>48) m=1,n+=3;
	}
	while (a[1].num) {
		for (i=1;i<=1;i++) a[i].num--;
		fill4(n,m);
		m+=2;if (m>48) m=1,n+=3;
	}
	printf("50 50\n");
	for (i=1;i<=50;i++) {
		for (j=1;j<=50;j++) {
			if (s[i][j]==0) printf("%c",a[4].ch); else printf("%c",s[i][j]);
		}
		printf("\n");
	}
	return 0;
}
