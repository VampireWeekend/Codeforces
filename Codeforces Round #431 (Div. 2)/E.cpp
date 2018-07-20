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
#include <stack>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
#define N 100000
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=100005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int a[maxn],t[maxn];
ll ans[maxn],f[maxn];
int num,qn;
set<int> s[maxn];

struct query {
	int type,pos,id,pre,val;
	bool operator< (const query &x) const {
		return pos<x.pos || (pos==x.pos&&type<x.type);
	}
};
query q[maxn*7],tem[maxn*7];

int lowbit(int x) {
	return x&(-x);
}

ll getsum(int tt) {
	ll sum=0;
	for (int t=tt;t;t-=lowbit(t)) 
		sum+=f[t];
	return sum;
}

void update(int tt,ll c) {
	int t=tt;
	for (int t=tt;t<=N;t+=lowbit(t))
		f[t]+=c;
}

void cdq(int l,int r) {
	int mid=(l+r)/2;
	if (l!=r) cdq(l,mid),cdq(mid+1,r);
	int h=l,t=mid+1,cnt=0;
	while (h<=mid&&t<=r) {
		if (q[h]<q[t]) {
			if (q[h].type==1) update(q[h].id,q[h].pre);
			tem[cnt++]=q[h++];
		} else {
			if (q[t].type==2) ans[q[t].val]-=getsum(q[t].pre)-getsum(q[t].id-1);
			    else if (q[t].type==3) ans[q[t].val]+=getsum(q[t].pre)-getsum(q[t].id-1);
			tem[cnt++]=q[t++];
		}
	}
	int o=h;
	for (;h<=mid;h++)
		tem[cnt++]=q[h];
	for (;t<=r;t++) {
		if (q[t].type==2) ans[q[t].val]-=getsum(q[t].pre)-getsum(q[t].id-1);
			else if (q[t].type==3) ans[q[t].val]+=getsum(q[t].pre)-getsum(q[t].id-1);
		tem[cnt++]=q[t];
	}
	for (int i=l;i<o;i++) if (q[i].type==1) update(q[i].id,-q[i].pre);
	for (int i=0;i<cnt;i++) q[l+i]=tem[i];
}

int main() {
	int n,m,i,x,y,z;
	scanf("%d%d",&n,&m);
	mem0(t);
	num=qn=0;
	for (i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		s[a[i]].insert(i);
		if (t[a[i]]!=0) 
			q[++num]=(query){1,i,t[a[i]],i-t[a[i]],0};
		t[a[i]]=i;
	}
	set<int>::iterator it,j,k;
	for (i=1;i<=m;i++) {
		scanf("%d%d%d",&z,&x,&y);
		if (z==1) {
			it=s[a[x]].find(x);j=k=it;k++;
			if (it!=s[a[x]].begin()) {
				j--;
				q[++num]=(query){1,x,*j,*j-x,0};
				if (k!=s[a[x]].end()) q[++num]=(query){1,*k,*j,*k-*j,0};
			}
			if (k!=s[a[x]].end()) q[++num]=(query){1,*k,x,x-*k,0};
			s[a[x]].erase(it);
			s[y].insert(x);
			a[x]=y;
			j=k=it=s[y].find(x);
			k++;
			if (it!=s[y].begin()) {
				j--;
				q[++num]=(query){1,x,*j,x-*j,0};
				if (k!=s[y].end()) q[++num]=(query){1,*k,*j,*j-*k,0};
			}
			if (k!=s[y].end()) q[++num]=(query){1,*k,x,*k-x,0};
		} else {
			q[++num]=(query){2,x-1,x,y,++qn};
			q[++num]=(query){3,y,x,y,qn};
		}
	}
	mem0(ans);mem0(f);
/*	for (i=1;i<=num;i++) {
		printf("%d %d %d %d %d %d\n",i,q[i].type,q[i].pos,q[i].id,q[i].pre,q[i].val);
	}*/
	cdq(1,num);
	for (i=1;i<=qn;i++) printf("%I64d\n",ans[i]);
	return 0;
}

