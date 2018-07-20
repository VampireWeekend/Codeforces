#include <cstdio>
#include <iostream>
#include <vector>
#include <string.h>
#include <map>
#include <algorithm>
#include <set>
#include <math.h>
#include <cmath>
#include <queue>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
const int maxn=2000005;
int s[maxn],f[maxn];
char a[maxn];

int find(int now) {
	if (f[now]==now) return now; else {
		f[now]=find(f[now]);
		return f[now];
	}
}

int main()  {
	mem0(s);
	int n,i,j,m,len,x,maxlen=0;
	scanf("%d",&n);
	for (i=1;i<maxn;i++) f[i]=i; 
	for (i=1;i<=n;i++) {
		scanf("%s",a);
		len=strlen(a);
		scanf("%d",&m);
		for (j=1;j<=m;j++) {
			scanf("%d",&x);
			maxlen=max(maxlen,x+len-1);
			int pos=find(x);
			while (pos<=x+len-1) {
				s[pos]=(int)a[pos-x];
				f[pos]=pos+1;
				pos=find(pos);
			}
		}
	}
	for (i=1;i<=maxlen;i++) {
		if (s[i]) printf("%c",(char)s[i]); else printf("a");
	}
	return 0;
}
