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
bool f[maxn];

struct num{
	int a,b,id;
};
num p[maxn];

bool cmp(num x,num y) {
	return x.a>y.a;
}

int main() {
	int i,n;
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		scanf("%d",&p[i].a);
		p[i].id=i;
	}
	for (i=1;i<=n;i++)
		scanf("%d",&p[i].b);
	sort(p+1,p+n+1,cmp);
	mem0(f);
	f[p[1].id]=1;
	p[n+1].b=-1;
	int sum=1;
	for (i=2;i<=n;i+=2) {
		if (p[i].b<p[i+1].b) f[p[i+1].id]=1; else f[p[i].id]=1; 
		sum++;
	}
	printf("%d\n",sum);
	for (i=1;i<=n;i++) {
		if (f[i]) printf("%d ",i);
	}
	return 0;
}

