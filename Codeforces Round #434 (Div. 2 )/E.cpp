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
typedef double db;
const int maxn=100005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int len[maxn],t[maxn],ans[maxn];
char s[maxn][10];
bool f[maxn],e[maxn];

int main() {
	int n,i,j,sum=0;
	scanf("%d",&n);
	mem0(f);mem0(e);
	for (i=1;i<=n;i++) {
		scanf("%s",s[i]);
		scanf("%d",&t[i]);
		sum+=t[i];
		len[i]=strlen(s[i]);
	}
	for (i=1;i<=n;i++) {
		int q=0;
		for (j=0;j<len[i];j++) {
			if (s[i][j]>='0'&&s[i][j]<='9') {
				q=q*10+s[i][j]-'0';
			} else {
				q=-1;
				break;
			}
		}
		if (q==-1) continue;
		if (t[i]==1) {
			if (q<=sum) f[q]=1,e[i]=1;
		} else {
			if (q>sum&&q<=n) f[q]=1,e[i]=1;
		}
	}
	int tot=0,l=1,r=sum+1;
	while (l<=sum&&f[l]) l++;
	while (r<=n&&f[r]) r++;
	for (i=1;i<=n;i++) {
		if (!e[i]) {
			tot++;
			if (t[i]==1) {
				ans[i]=l++;
				while (l<=sum&&f[l]) l++;
			} else {
				ans[i]=r++;
				while (r<=n&&f[r]) r++;
			}
		} 
	}
	printf("%d\n",tot);
	for (i=1;i<=n;i++) {
		if (!f[i]) {
			printf("move %s %d\n",s[i],ans[i]);
		}
	}
	return 0;
}

