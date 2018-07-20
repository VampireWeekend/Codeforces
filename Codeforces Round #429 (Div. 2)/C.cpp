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
const int maxn=200005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);  
struct num{
	int val,id;
};
num a[maxn],b[maxn];

int ans[maxn];

bool cmp(num a,num b) {
	return a.val>b.val;
}

bool bcmp(num a,num b) {
	return a.val<b.val;
}

int main() {
//	freopen("F.in","r",stdin);
//	freopen("F.out","w",stdout);
	int i,j,n,m;
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		scanf("%d",&a[i].val);
		a[i].id=i;
	}
	for (i=1;i<=n;i++) {
		scanf("%d",&b[i].val);
		b[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	sort(b+1,b+n+1,bcmp);
	for (i=1;i<=n;i++) {
		ans[b[i].id]=a[i].val;
	}
	for (i=1;i<=n;i++) printf("%d ",ans[i]);
	return 0;
}

