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
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
#define N 3000000
#define num0 9592
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=100005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
ll a[N],b[maxn];
bool prime[N+5];
vector<int> v[N+5];
int num=0;

void init() {
	num=0;
	memset(prime,0,sizeof(prime));
	int i,j;
	for (i=2;i<=N;i++) {
		if (!prime[i])
			a[++num]=i;
		for (j=1;j<=num&&i*a[j]<=N;j++) {
			prime[i*a[j]]=1;
			if (i%a[j]==0)
				break;
		}
	}
}

int main() {
	int n,i,j,k,flag=-1,l;
	init();
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		scanf("%d",&b[i]);
		int x=b[i];
		for (j=1;j<=num0;j++) {
			if (x%a[j]==0) {
				while (x%a[j]==0) x/=a[j];
				if (v[a[j]].size()>0) {
					flag=v[a[j]][0];break; 
				} 
				if (x==1) break;
			}
		}
		if (flag!=-1)
			break;
		for (j=1;j<=num0;j++) 
			if (b[i]%a[j]==0) {
				v[a[j]].push_back(i);
			} 
	}
	if (flag==-1) {
		for (i=1;i<=n;i++) {
			printf("%d ",b[i]);
		} 
		return 0;
	}
	for (j=b[i]+1;;j++) {
		int x=j,fff=-1;
		for (l=1;l<=num0;l++) {
			if (x%a[l]==0) {
				while (x%a[l]==0) x/=a[l];
				if (v[a[l]].size()>0) {
					fff=1;break; 
				} 
				if (x==1) break;
			}
		}
		if (fff==-1) {
			b[i]=j;
			int y=j;
			for (l=1;y!=1;l++) 
				if (y%a[l]==0) {
					v[a[l]].push_back(i);
					while (y%a[l]==0) y/=a[l];
				} 
			break;
		}
	}
	for (k=1;k<=i;k++) {
		printf("%d ",b[k]);
	}
	l=0;
	for (k=i+1;k<=n;k++) {
		l++;
		while (v[a[l]].size()>0) 
			l++;
		printf("%d ",a[l]);
	}
	return 0;
}
