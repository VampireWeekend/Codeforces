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
const int maxn=25,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int ans[maxn];
struct node{
	int v,id;
};
node a[maxn];

bool cmp(node a,node b) {
	return a.v>b.v;
}

int main() {
	int n,i;
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	for (i=1;i<n;i++) ans[a[i].id]=a[i+1].v;
	ans[a[n].id]=a[1].v;
	for (i=1;i<=n;i++) printf("%d ",ans[i]);
	return 0;
}
