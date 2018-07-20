//http://blog.csdn.net/dormousenone/article/details/71422868
//Codeforces Round #412 D. Dynamic Problem Scoring £¨Ã¶¾Ù + Ì°ÐÄ£©
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
const int mod=1e9+7;
const int maxn=125;
int a[maxn][6];
int sum[6],num[6];

int main() {
	int n,i,j;
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		for (j=1;j<=5;j++) {
		    scanf("%d",&a[i][j]);
		    if (a[i][j]!=-1) num[j]++;   
	    }
	}
	for (j=1;j<=5;j++) sum[j]=num[j];
	for (j=1;j<=5;j++) {
		if (a[1][j]!=-1) {
			if (!(a[1][j]!=-1&&a[2][j]!=-1&&a[1][j]<a[2][j])) q.push(j);
		}
		point[1][j]=500
	}
	return 0;
}
