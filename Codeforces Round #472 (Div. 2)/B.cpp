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
const int maxn=55,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
char s[maxn][maxn];
int f[maxn*2];

int find(int now) {    
    if (f[now]==now) return now; else {    
        f[now]=find(f[now]);    
        return f[now];    
    }    
}   

int main() {
	int n,m,i,j;
	scanf("%d%d",&n,&m);
	for (i=1;i<=n+m;i++) f[i]=i;
	for (i=1;i<=n;i++) {
		scanf("%s",s[i]+1);
		for (j=1;j<=m;j++) {
			if (s[i][j]=='#') {
				int fa=find(i),fb=find(j+n);
				if (fa!=fb) {
					f[fa]=fb;
				}
			}
		}
	} 
	int flag=1;
	for (i=1;i<=n;i++) {
		for (j=1;j<=m;j++) {
			int fa=find(i),fb=find(j+n);
			if (s[i][j]=='#'&&fa!=fb) flag=0;
			if (s[i][j]=='.'&&fa==fb) flag=0;
		}
	}
	if (flag) cout << "Yes"; else cout << "No";
	return 0;
}
