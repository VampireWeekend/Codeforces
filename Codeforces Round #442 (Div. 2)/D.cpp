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
const int maxn=1005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int dp[maxn][maxn];
char s[maxn][maxn];
bool inque[maxn][maxn]; 
int n,m;

struct node{
	int x,y,k;
	node(int x,int y,int k): x(x),y(y),k(k) {}
};

bool judge(int x,int y) {
	return x>0&&x<=n&&y>0&&y<=m;
}

int main() {
	int k,i,j,sx,sy,tx,ty;
	scanf("%d%d%d",&n,&m,&k);
	for (i=1;i<=n;i++) {
		scanf("%s",s[i]+1); 
	}
	scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
	if (sx==tx&&sy==ty) {
		printf("0");return 0;
	}
	mem0(inque);
	queue<node> q;
	meminf(dp);dp[sx][sy]=0;
	if (s[sx][sy]!='#') q.push(node(sx,sy,0));
	int ans=-1,flag=0;
	while (!q.empty()) {
		node now=q.front();q.pop();
//		cout << now.x << ' ' << now.y << ' ' << now.k << endl; 
		for (i=1;i<=k;i++) {
			if (!judge(now.x+i,now.y)) break;
			if (dp[now.x+i][now.y]<now.k+1||s[now.x+i][now.y]=='#') break;
			if (now.x+i==tx&&now.y==ty) {
				ans=now.k+1;flag=1;break;
			} else if (!inque[now.x+i][now.y]) {
				inque[now.x+i][now.y]=1;
				q.push(node(now.x+i,now.y,now.k+1)),dp[now.x+i][now.y]=now.k+1;
			}
		}
		if (flag) break;
		for (i=1;i<=k;i++) {
			if (!judge(now.x-i,now.y)) break;
			if (dp[now.x-i][now.y]<now.k+1||s[now.x-i][now.y]=='#') break;
			if (now.x-i==tx&&now.y==ty) {
				ans=now.k+1;flag=1;break;
			} else if (!inque[now.x-i][now.y]) {
				inque[now.x-i][now.y]=1;
				q.push(node(now.x-i,now.y,now.k+1)),dp[now.x-i][now.y]=now.k+1;
			}
		}
		if (flag) break;
		for (i=1;i<=k;i++) {
			if (!judge(now.x,now.y+i)) break;
			if (dp[now.x][now.y+i]<now.k+1||s[now.x][now.y+i]=='#') break;
			if (now.x==tx&&now.y+i==ty) {
				ans=now.k+1;flag=1;break;
			} else if (!inque[now.x][now.y+i]) {
				inque[now.x][now.y+i]=1;
				q.push(node(now.x,now.y+i,now.k+1)),dp[now.x][now.y+i]=now.k+1;
			}
		}
		if (flag) break;
		for (i=1;i<=k;i++) {
			if (!judge(now.x,now.y-i)) break;
			if (dp[now.x][now.y-i]<now.k+1||s[now.x][now.y-i]=='#') break;
			if (now.x==tx&&now.y-i==ty) {
				ans=now.k+1;flag=1;break;
			} else if (!inque[now.x][now.y-i]) {
				inque[now.x][now.y-i]=1;
				q.push(node(now.x,now.y-i,now.k+1)),dp[now.x][now.y-i]=now.k+1;
			}
		}
		if (flag) break;
	}
	printf("%d\n",ans);
	return 0;
}
/*
5 5 3
..#..
.....
.....
.....
.....
3 3 1 2
*/
