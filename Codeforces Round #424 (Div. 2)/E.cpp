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
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=100005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
ll f[maxn];
vector<int> v[maxn];
int n;

struct card{
	ll num,pos;
};
card a[maxn];

bool cmp(card a,card b) {
	return a.num<b.num || (a.num==b.num&&a.pos<b.pos);
}

int lowbit(int x) {
	return x&(-x);
}

ll findsum(int p) {
	ll sum=0;
	int i;
	for (i=p;i>0;i-=lowbit(i)) 
		sum+=f[i];
	return sum;
}

void update(int p,ll val) {
	int i;
	for (i=p;i<=n;i+=lowbit(i)) 
		f[i]+=val;
}

int main() {
	int i;
	scanf("%d",&n);
	mem0(f);
	for (i=1;i<=n;i++) {
		scanf("%I64d",&a[i].num);
		a[i].pos=i;
		update(i,1);
		v[a[i].num].push_back(i);
	}
	sort(a+1,a+n+1,cmp);
	ll ans=0;
	a[0].num=0;
	for (i=1;i<=n;i++) 
	    if (a[i].num!=a[i-1].num) sort(v[a[i].num].begin(),v[a[i].num].end());
	int last;
	last=ans=a[1].pos;
	update(a[1].pos,-1);
	for (i=2;i<=n;i++) {
		int pos=upper_bound(v[a[i].num].begin(),v[a[i].num].end(),last)-v[a[i].num].begin();
		if (pos==v[a[i].num].size()) pos=0;
		pos=v[a[i].num][pos];
		if (pos>=last) 
		    ans+=findsum(pos)-findsum(last);
		else 
			ans+=findsum(pos)+findsum(n)-findsum(last);
		last=pos;
		update(pos,-1);
	}
	printf("%I64d\n",ans);
	return 0;
}
