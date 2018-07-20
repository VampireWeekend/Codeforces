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
int a[maxn][maxn];
int ans,N,M;

void dfs(int x,int y) {
	if (x==N+1) {
		int sum;
		for (int i=1;i<=N;i++) {
			sum=1;
			for (int j=1;j<=M;j++) 
				sum*=a[i][j];
			if (sum!=1) return;
		}
		for (int i=1;i<=M;i++) {
			sum=1;
			for (int j=1;j<=N;j++) 
				sum*=a[j][i];
			if (sum!=1) return;
		}
		ans++;
/*		for (int i=1;i<=N;i++) {
			for (int j=1;j<=M;j++) 
				cout << a[i][j] << ' ';
			cout << '\n';
		}
		cout << '\n';*/
	} else {
		if (y==M) {
			a[x][y]=1,dfs(x+1,1);a[x][y]=-1,dfs(x+1,1);
		} else {
			a[x][y]=1,dfs(x,1+y);a[x][y]=-1,dfs(x,1+y);
		}
	}
}

int main() {
	int n,m,k;
	cin >> N >> M;
	ans=0;dfs(1,1);
	cout << ans;
	return 0;
}
