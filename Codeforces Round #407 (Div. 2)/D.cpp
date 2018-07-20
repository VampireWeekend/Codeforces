#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <string.h>
#include <set>
//无向图存在欧拉路当且仅当它是连通的，且除了恰好两个顶点外，其余所有顶点的度为偶数。
const int maxn=1000005;
using namespace std;
typedef long long ll;           //坑! 
int n,x,y,sum;
ll ans,m,self;
ll a[maxn];
int f[maxn];
//vector<int> c[maxn];
set<int> se;

int find(int now){
	if (f[now]==now) return now; else {
		f[now]=find(f[now]);
		return f[now];
	}
}

void unite(int x,int y) {
	f[find(x)]=find(y);
}


int main() 
{
	cin >> n >> m;
	int i;
	memset(a,0,sizeof(a));
	self=0;
	for (i=1;i<=n;i++) f[i]=i;
	for (i=1;i<=m;i++) {
		scanf("%d%d",&x,&y);
		if (x!=y) {
			a[x]++;a[y]++;
	//    	c[x].push_back(y);c[y].push_back(x);
	    	unite(x,y);
		} else self++;
		se.insert(x);
	    se.insert(y);
	}
	int fa=find(*se.begin());
	for (set<int>::iterator it=se.begin();it!=se.end();it++) {
		if (find(*it)!=fa) {
			cout << 0 << endl;
			return 0; 
		} 
	}
	ans=0;
	for (i=1;i<=n;i++) {
		ans+=(a[i]-1)*a[i]/2;
	}
	ans+=(self-1)*self/2;
	ans+=(m-self)*self;
	cout << ans;
	return 0;
}
