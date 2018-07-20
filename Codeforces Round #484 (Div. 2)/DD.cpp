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
const int maxn=100005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int c[maxn],cnt[maxn],s[maxn];

struct node {
	int w,p;
};
node a[maxn];

bool cmp(node a,node b) {
	return a.w<b.w;
}

int main() {
	int n,i,j;
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		scanf("%d",&a[i].w);
		a[i].p=i;
	}
	sort(a+1,a+n+1,cmp);
	int maxloc=-1,ans=inf;
	for (i=1;i<=n;i++) {
		int sum=0;
		if (a[i].p!=1)
		if (c[a[i].p-1]) {
			sum++;
			c[a[i].p]=c[a[i].p-1];
			cnt[s[c[a[i].p]]]--;
			s[c[a[i].p]]++;
			cnt[s[c[a[i].p]]]++;
		} 
		if (a[i].p!=n)
		if (c[a[i].p+1]) {
			if (sum) {
				if (s[c[a[i].p+1]]>s[c[a[i].p]]) {
					int pos=a[i].p;
					s[c[a[i].p+1]]+=s[c[a[i].p]];
					cnt[s[c[a[i].p]]]--;cnt[s[c[a[i].p+1]]+s[c[a[i].p]]]++;
					int q=c[pos];
					c[a[i].p]=c[a[i].p+1];
					while (pos>1&&c[pos-1]==q) {
						pos--;
						c[pos]=c[pos+1];
					}
				} else {
					int pos=a[i].p+1;
					s[c[a[i].p]]+=s[c[a[i].p+1]];
					cnt[s[c[a[i].p+1]]]--;cnt[s[c[a[i].p+1]]+s[c[a[i].p]]]++;
					c[a[i].p+1]=c[a[i].p];
					int q=c[pos];
					while (pos<n&&c[pos+1]==q) {
						pos++;
						c[pos]=c[pos-1];
					}
				}
			} else {
				c[a[i].p]=c[a[i].p+1];
				cnt[s[c[a[i].p]]]--;
				s[c[a[i].p]]++;
				cnt[s[c[a[i].p]]]++;
			}
			sum++;
		}
		if (sum==0) c[a[i].p]=a[i].p,cnt[1]++,s[a[i].p]=1;
		if (cnt[s[c[a[i].p]]]*s[c[a[i].p]]==i&&(a[i].w!=a[i+1].w||i==n)) {
			if (maxloc<cnt[s[c[a[i].p]]]) {
				maxloc=max(maxloc,cnt[s[c[a[i].p]]]);
				ans=a[i].w+1;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
