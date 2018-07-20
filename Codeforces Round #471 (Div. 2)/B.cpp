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
char s[maxn];
int a[35];

int main() {
	scanf("%s",s+1);
	int i;
	mem0(a);
	int n=strlen(s+1),cnt=0;
	for (i=1;i<=n;i++) {
		if (a[s[i]-'a']==0) cnt++;
		a[s[i]-'a']++;
	}
	if (cnt==4) {
		printf("Yes\n");
		return 0;
	}
	if (cnt==3) {
		for (i=0;i<26;i++) {
			if (a[i]>1) {
				printf("Yes\n");
				return 0;
			}
		}
		printf("No\n");
		return 0;
	}
	if (cnt==2) {
		for (i=0;i<26;i++) {
			if (a[i]==1) {
				printf("No\n");
				return 0;
			}
		}
		printf("Yes\n");
		return 0;
	}
	printf("No\n");
	return 0;
}
