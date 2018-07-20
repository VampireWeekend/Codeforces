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
int a[maxn],p[35];
char s[maxn];

int main() {
	scanf("%s",s);
	int len,i,l=-1,j;
	len=strlen(s);
	memset(a,-1,sizeof(a));
	memset(p,-1,sizeof(p));
	for (i=0;i<len;i++) {
		if (l==-1) {
			if (s[i]=='a') {
				a[i]=0;
				p[0]=1;
				l=1;
			}
		} else {
			int pos=s[i]-'a';
			for (j=25;j>=pos;j--) {
				if (j==0) break;
				if (p[j-1]!=-1) {
					p[j]=1;a[i]=j;break;
				}
			}
			if (a[i]==25) {
				for (j=0;j<len;j++) {
					if (a[j]==-1) printf("%c",s[j]); 
						else printf("%c",(char)('a'+a[j]));
				}
				return 0;
			}
		}
	}
	printf("-1");
	return 0;
}
