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
const int maxn=4,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int x[maxn],y[maxn],ax[maxn],ay[maxn];

int solve() {
	int ans=2*inf;
	int i,j;
	for (auto y1:y) {
		for (auto y2:y) {
			if (y1==y2) continue;
			int d=abs(y1-y2);          //枚举矩形边长 
			set<int> st;
			//枚举左上角 
			for (auto x1:x)
				for (auto x2:x) 
					for (auto r: {0,-d,-2*d,1,-d+1,-2*d+1})
						st.insert((x1+x2+r)/2);
			for (auto x1:st) {
				int p[4]={3,2,1,0};
				for (j=0;j<24;j++) {
					next_permutation(p,p+4);
					int nx[4]={x1,x1,x1+d,x1+d};
					int ny[4]={y1,y2,y1,y2};
					for (i=0;i<4;i++)
						if (nx[i]!=x[p[i]]&&ny[i]!=y[p[i]]) break;
					if (i!=4) continue;
					int u=0;
					for (i=0;i<4;i++) 
						u=max(u,abs(nx[i]-x[p[i]])+abs(ny[i]-y[p[i]]));
					if (u<ans) {
						ans=u;
						for (i=0;i<4;i++) 
							ax[p[i]]=nx[i],ay[p[i]]=ny[i];
					}
				}
			}
		}
	}
	return ans;
}

int main() {
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		int i,ans;
		for (i=0;i<4;i++) {
			scanf("%d %d",&x[i],&y[i]);
			x[i]+=1e9;y[i]+=1e9;
		}
		int z1,z2;
		z1=solve();
		swap(x,y);swap(ax,ay);
		z2=solve();
		swap(x,y);swap(ax,ay);
		if (z1==z2&&z2==2*inf) {
			printf("-1\n");
		} else {
			if (z1<z2) ans=solve(); else ans=z2;
			printf("%d\n", ans);
			for (i=0;i<4;i++) ax[i]-=1e9,ay[i]-=1e9;
			for (i=0;i<4;i++) printf("%d %d\n",ax[i],ay[i]);
		}
	}
//	system("pause");
	return 0;
}
