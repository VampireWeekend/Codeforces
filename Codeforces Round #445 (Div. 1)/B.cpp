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
int in[35],out[35];
bool d[35][35];
string a[maxn],ans;
bool visit[35],p[35];

bool dfs(int now) {
	visit[now]=1;
	ans=ans+(char)(now+'a');
	for (int j=0;j<26;j++) {
		if (d[now][j]) {
			if (visit[j]) return false;
			return dfs(j);
		}
	}
	return true;
}

int main() {
	int n,i,j,len;
	scanf("%d",&n);
	mem0(d);mem0(p);
	int flag=0;
	for (i=1;i<=n;i++) {
		cin >> a[i];
		int len=a[i].length();
		for (j=0;j<len-1;j++) {
			d[a[i][j]-'a'][a[i][j+1]-'a']=1;
	//		cout << a[i][j]-'a' <<' ' << a[i][j+1]-'a' << endl;
		}
		if (len==1) p[a[i][0]-'a']=1;
	}
	for (i=0;i<26;i++)
	if (d[i][i]) {
		printf("NO\n");return 0;
	}
	for (i=0;i<26;i++) {
		for (j=0;j<26;j++) {
			if (d[i][j]) in[j]++,out[i]++;
		}
	}
	for (i=0;i<26;i++) {
		if (in[i]>1||out[i]>1) {
			printf("NO\n");return 0;
		}
	}
	mem0(visit);
	ans="";
	for (i=0;i<26;i++) {
		if (out[i]!=0&&in[i]==0) {
			if (!dfs(i)) {
				printf("NO\n");return 0;
			}
		}
		if (p[i]&&in[i]==0&&out[i]==0) ans=ans+(char)(i+'a');
	}
	for (i=0;i<26;i++) {
		if (out[i]!=0||in[i]!=0) {
			if (!visit[i]) {
				printf("NO\n");return 0;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
