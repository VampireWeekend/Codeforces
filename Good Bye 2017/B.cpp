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
const int maxn=105,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
char a[maxn][maxn],s[maxn];
int n,m;

bool check(int i,int j) {
	if (i>0&&i<=n&&j>0&&j<=m&&a[i][j]!='#') return true;
	return false;
}

int main() {
	int i,j,k,l,sx,sy,tx,ty,len,p;
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++) {
		scanf("%s",a[i]+1);
		for (j=1;j<=m;j++) {
			if (a[i][j]=='S') sx=i,sy=j;
			if (a[i][j]=='E') tx=i,ty=j;
		}
	}
	scanf("%s",s);
	int ans=0;len=strlen(s);
	for (i=0;i<=3;i++) {
	for (j=0;j<=3;j++) {
		if (i==j) continue;
	for (k=0;k<=3;k++) {
		if (i==k||j==k) continue;
	for (l=0;l<=3;l++) {
		if (l==i||l==j||l==k) continue;
		int x=sx,y=sy,flag=1;
		for (p=0;p<len;p++) {
			if (s[p]-'0'==i) x++;
			if (s[p]-'0'==j) x--;
			if (s[p]-'0'==k) y++;
			if (s[p]-'0'==l) y--;
			if (!check(x,y)) {
				flag=0;break;
			}
			if (x==tx&&y==ty) break;
		}
		if (!flag) continue;
		if (x==tx&&y==ty) ans++;
	} 
	} 	
	} 
	} 
	cout << ans;
	return 0;
}
