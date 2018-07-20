#include <cstdio>
#include <iostream>
#include <string.h>
#include <string> 
#include <map>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=105,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L); 
int a[maxn]; 

int main() {
	int n,k,i,center,side;
	scanf("%d%d",&n,&k);
	for (i=1;i<=k;i++) {
		scanf("%d",&a[i]);
	}
	center=side=2*n;
	if (side<0) {
		printf("NO");
		return 0;
	}
	int one,two;one=two=0;
	for (i=1;i<=k;i++) {
		if (a[i]%4==2) two++;
		if (a[i]%4==1) one++;
	}
	int num=min(one,two);
	two-=num;one-=num;
	num*=2;
	if (center-num>=0) {
		center-=num;
		num=0;
	} else {
		num-=center/2*2;
		center%=2;
	}
	one+=num/2;two+=num/2;
	for (i=1;i<=two;i++) {
		if (side>0) side--; else center-=2;
	}
	int sum=center+side;
	sum-=one;
	for (i=1;i<=k;i++) {
		if (a[i]%4==2) sum-=a[i]/2-1;
		if (a[i]%4==1) sum-=a[i]/2;
	}
	for (i=1;i<=k;i++) {
		if (a[i]%4==3) 
			sum-=a[i]/2+1;
	}
	for (i=1;i<=k;i++) {
		if (a[i]%4==0) 
			sum-=a[i]/2;
	}
	if (sum<0) {
		printf("NO");
		return 0;
	}
	printf("YES");
	return 0;
}
