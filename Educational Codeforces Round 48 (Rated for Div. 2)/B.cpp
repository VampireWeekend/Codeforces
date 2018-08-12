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
#include <assert.h>
#define pb push_back 
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef pair<int,int> pp;
const int maxn=1005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
int next[maxn],sum[maxn];
char s[maxn],t[maxn];

void buildnext(char s[]) {
	int len=strlen(s);
	int j=0;
	next[0]=next[1]=0;
	for (int i=1;i<len;i++) {
		while (j>0&&s[i]!=s[j])
		    j=next[j];
		if (s[i]==s[j]) j++;
		next[i+1]=j;
	}
}

int main() {
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	scanf("%s",s);
	int lens=strlen(s);
	scanf("%s",t);
	int lent=strlen(t);
	buildnext(t);
	j=0;
	for (int i=0;i<lens;i++) {
	    	while (j>0&&t[j]!=s[i]) 
	     	   j=next[j];
	   	 if (t[j]==s[i]) j++;
	   	 if (j==lent) {
			sum[i-lent]++;j=next[j];
		 }
	}
	for (int i=1;i<=1000;i++) sum[i]+=sum[i-1];
	for (int i=1;i<=q;i++) {
		scanf("%d%d",&l,&r);
		l--;r--;
		printf("%d\n",sum[r]-sum[l-1]);
	}
	return 0;
}
