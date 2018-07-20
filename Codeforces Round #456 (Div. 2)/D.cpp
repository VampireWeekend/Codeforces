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
map<ll,int> mp;

struct node{
	ll ex,i,j;
	node(ll ex,ll i,ll j): ex(ex),i(i),j(j) {}
	bool operator <(const node &x)const {
		return ex<x.ex;
	}
};
priority_queue<node> pq;

int main() {
	ll n,m,c,k,i,j,l,r,u,d,x,y;
	ll sum=0;
	ll dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};  
	cin >> n >> m >> c >> k;
	x=(n+1)/2,y=(m+1)/2;
	mp[x*(ll)100000+y]=1;
	u=max(1LL,x-c+1);d=min(n,x+c-1);
	l=max(1LL,y-c+1);r=min(m,y+c-1);
	pq.push(node((d-u-c+2)*(r-l-c+2),x,y));
	while (k--) {
		node now=pq.top();pq.pop();
		sum+=now.ex;
		for (i=0;i<4;i++) {
			x=now.i+dir[i][0];y=now.j+dir[i][1];
			if (!mp[x*(ll)100000+y]) {
				mp[x*(ll)100000+y]=1;
				u=max(1LL,x-c+1);d=min(n,x+c-1);
				l=max(1LL,y-c+1);r=min(m,y+c-1);
				pq.push(node((d-u-c+2)*(r-l-c+2),x,y));
			}
		}
	}
	db ans=((db)sum)/(db)((n-c+1)*(m-c+1));
	printf("%.9lf",ans);
	return 0;
}
