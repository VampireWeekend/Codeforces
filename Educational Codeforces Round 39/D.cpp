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
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=505,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int dp[maxn],val[maxn];
vector<int> v;

int main() {
	int n,m,k,sum=0,cnt=0,i,j,l;
	scanf("%d%d%d",&n,&m,&k);
	dp[0]=0;
	for (i=1;i<=n;i++) {
		v.clear();
		int first=-1,last=-1;
		for (j=1;j<=m;j++) {
			char c='a';
			while (!(c>='0'&&c<='9')) scanf("%c",&c);
			if (c=='1') {
				if (first==-1) first=j;
				last=j;
				v.push_back(j);
			}
		}
		if (first==-1) continue;
		sum+=last-first+1;
		for (j=1;j<=k;j++) val[j]=0;
		int size=v.size();
		for (j=1;j<size;j++) {
			for (l=0;l<=j;l++) {
				val[j]=max(val[j],v[l]-v[0]+v[size-1]-v[size-(j-l)-1]);
			}
		}
		val[size]=last-first+1;
		for (j=k;j>=1;j--) {
			for (l=1;l<=j;l++) {
				dp[j]=max(dp[j],dp[j-l]+val[l]);
			}
		}
	}
	printf("%d",sum-dp[k]);
	return 0;
}
