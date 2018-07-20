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
const int maxn=100005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);  
int a[maxn];
bool f[maxn];
vector<int> v[maxn];

struct Num{
	int id,val;
};
Num b[maxn];

bool cmp(Num a,Num b) {
	return a.val<b.val;
}

int main() {
	int n,i,ans=0,j;
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		scanf("%d",&b[i].val);
		b[i].id=i;
	}
	sort(b+1,b+n+1,cmp);
	for (i=1;i<=n;i++) {
		a[b[i].id]=i;
	}
	mem0(f);
	for (i=1;i<=n;i++) {
		if (f[i]) continue;
		int now=i;
		ans++;
		while (!f[now]) {
			f[now]=1;
			v[ans].push_back(now);
			now=a[now];
		}
		
	}
	printf("%d\n",ans);
	for (i=1;i<=ans;i++) {
		printf("%d",v[i].size());
		for (j=0;j<v[i].size();j++) printf(" %d",v[i][j]);
		printf("\n");
	}
	return 0;
}

