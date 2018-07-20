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
#include <bitset>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=1005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);
char mp[maxn][maxn];

bool dfs(int step,char c) {
	int i,j;
	if (step==0) {
		for (i=1;i<=3;i++) {
			if (mp[i][1]==mp[i][2]&&mp[i][3]==mp[i][2]&&mp[i][3]==c) {
				return true;
			}
		}
		for (j=1;j<=3;j++) {
			if (mp[1][j]==mp[2][j]&&mp[3][j]==mp[2][j]&&mp[3][j]==c) {
				return true;
			}
		}
		if (mp[1][1]==mp[2][2]&&mp[3][3]==mp[2][2]&&mp[3][3]==c) {
			return true;
		}
		if (mp[1][3]==mp[2][2]&&mp[3][1]==mp[2][2]&&mp[1][3]==c) {
			return true;
		}
		return false;
	}
	int cnt=0,l=0;
	for (i=1;i<=3;i++) {
		for (j=1;j<=3;j++) {
			if (mp[i][j]=='.') {
				l++;
				if ((c=='x'&&step%2)||c=='o'&&step%2==0) mp[i][j]='x';
				else  mp[i][j]='o';
				cnt+=dfs(step-1,c);
				mp[i][j]='.';
			}
		}
	}
	if (step==1) return cnt!=0;
	if (step==2) return cnt==l;
}

int main() {
	int cas,i,j;
	scanf("%d",&cas);
	char c;
	while (cas--) {
		for (i=1;i<=3;i++) {
			for (j=1;j<=3;j++) {
				scanf("%c",&c);
				while (c!='x'&&c!='o'&&c!='.') scanf("%c",&c);
				mp[i][j]=c;
			}
		}
		scanf("%s",mp[4]);
		int k=(mp[4][0]=='x'?1:2),flag=0;
		for (i=1;i<=3;i++) {
			for (j=1;j<=3;j++) {
				if (mp[i][j]=='.') {
					mp[i][j]=mp[4][0];
					if (dfs(0,mp[4][0])||dfs(2,mp[4][0])) {
						printf("Kim win!\n");flag=1;
						break;
					}
					mp[i][j]='.';
				}
			}
			if (flag) break;
		}
		if (!flag) printf("Cannot win!\n");
	}
	return 0;
}

