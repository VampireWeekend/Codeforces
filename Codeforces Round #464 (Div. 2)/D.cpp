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
char s[maxn],t[maxn];
int f[105];
vector<int> v[maxn];

int find(int now) {  
    if (f[now]==now) return now; else {  
        f[now]=find(f[now]);  
        return f[now];  
    }  
} 

int main() {
	int len,i,j,ans=0;
	scanf("%d",&len);
	scanf("%s",s+1);
	scanf("%s",t+1);
	for (i=1;i<=26;i++) {
		f[i]=i;
	}
	for (i=1;i<=len;i++) {
		int fa=find(s[i]-'a'+1),fb=find(t[i]-'a'+1);
		if (fa==fb) continue;
		f[fa]=fb;
	}
	for (i=1;i<=26;i++) {
		int fa=find(i);
		v[fa].push_back(i);
	}
	for (i=1;i<=26;i++) if (v[i].size()>0) ans+=v[i].size()-1;
	printf("%d\n",ans);
	for (i=1;i<=26;i++) {
		if (v[i].size()>1) {
			for (j=1;j<v[i].size();j++) {
				printf("%c %c\n",(char)(v[i][j-1]+'a'-1),(char)(v[i][j]+'a'-1));
			}
		}
	}
	return 0;
}
