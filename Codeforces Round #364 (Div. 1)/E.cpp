#include <cstdio>
#include <string.h>
#include <string> 
#include <algorithm>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=200005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
int wa[maxn],wb[maxn],wv[maxn],wss[maxn],sa[maxn],ranki[maxn],height[maxn];
char s[maxn];
int a[maxn],mn[maxn][20];
int num,L,R;

struct node {
	int max, len;
};

struct Tree {
	int lc,rc,l,r,min;
	node c;
};
Tree tree[4*maxn];

node MAX(node a, node b) {
	if ((a.max > b.max || (a.max == b.max&&a.len < b.len))) return a; else return b;
}

int cmp(int *r,int a,int b,int l) {
	return r[a]==r[b]&&r[a+l]==r[b+l];
}

void build(int *r,int *sa,int n,int m) {
	int i,j,k,p,*x=wa,*y=wb,*t;
	for (i=0;i<m;i++) wss[i]=0;
	for (i=0;i<n;i++) wss[x[i]=r[i]]++;
	for (i=0;i<m;i++) wss[i]+=wss[i-1];
	for (i=n-1;i>=0;i--) sa[--wss[x[i]]]=i;
	for (j=1,p=1;p<n;j*=2,m=p) {
		for (p=0,i=n-j;i<n;i++) y[p++]=i;
		for (i=0;i<n;i++) if (sa[i]>=j) y[p++]=sa[i]-j;
		for (i=0;i<n;i++) wv[i]=x[y[i]];
		for (i=0;i<m;i++) wss[i]=0;
		for (i=0;i<n;i++) wss[wv[i]]++;
		for (i=1;i<m;i++) wss[i]+=wss[i-1];
		for (i=n-1;i>=0;i--) sa[--wss[wv[i]]]=y[i];
		t=x;x=y;y=t;
		p=1;x[sa[0]]=0;
		for (i=1;i<n;i++)  x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
	}
	for (i=1;i<n;i++) ranki[sa[i]]=i;k=0; 
	for (i=0;i<n-1;height[ranki[i++]]=k) {
		if (k) k--;
		for (j=sa[ranki[i]-1];r[i+k]==r[j+k];k++);
	}
}

void rmq(int n) {
	int i,j;
	for (i=1;i<=n;i++) mn[i][0]=height[i];
	for (j=1;(1<<j)<=n;j++) {
		for (i=1;i+(1<<j)-1<=n;i++) {
			mn[i][j]=min(mn[i][j-1],mn[i+(1<<(j-1))][j-1]);
		}
	}
}

int lcp(int fa,int fb) {
	if (fa>fb) swap(fa,fb);
	fa++;
	int k=0;
	while ((1<<(k+1))<=(fb-fa+1)) k++;
	return min(mn[fa][k],mn[fb-(1<<k)+1][k]);
}

void buildtree(int now,int l,int r) {
	tree[now].l=l;
	tree[now].r=r;
	tree[now].c.max=tree[now].c.len=0;
	tree[now].min=inf;
	if (l!=r) {
		num++;
		tree[now].lc=num;
		buildtree(num,l,(l+r)/2);
		num++;
		tree[now].rc=num;
		buildtree(num,(l+r)/2+1,r);
	}
}

void update1 (int now,int l,int r,int val,int len) {
	if (tree[now].l>=l&&tree[now].r<=r) {
		if (val>tree[now].c.max||(val==tree[now].c.max&&len<tree[now].c.len))
			tree[now].c.max=val,tree[now].c.len=len;
	} else {
		if (l<=(tree[now].l+tree[now].r)/2) 
		    update1(tree[now].lc,l,r,val,len);
		if (r>(tree[now].l+tree[now].r)/2)
		    update1(tree[now].rc,l,r,val,len);
//		tree[now].c = MAX(tree[tree[now].lc].c, tree[tree[now].rc].c);
	}
}

void update2 (int now,int pos,int val) {
	if (tree[now].l==pos&&tree[now].r==pos) {
		tree[now].min=val;
	} else {
		if (pos<=(tree[now].l+tree[now].r)/2) 
		    update2(tree[now].lc,pos,val);
		if (pos>(tree[now].l+tree[now].r)/2)
		    update2(tree[now].rc,pos,val);
		tree[now].min=min(tree[tree[now].lc].min,tree[tree[now].rc].min);
	}
}

node findval (int now,int pos) {
	if (tree[now].l==pos&&tree[now].r==pos) 
		return tree[now].c;
	else 
		if (pos<=(tree[now].l+tree[now].r)/2) 
		    return MAX(tree[now].c, findval(tree[now].lc, pos));
		else
		    return MAX(tree[now].c,findval(tree[now].rc, pos));
}

int findmin(int now,int l,int r) {
	if (tree[now].l>=l&&tree[now].r<=r) {
		return tree[now].min;
	} else {
		int ans=inf;
		if (l<=(tree[now].l+tree[now].r)/2) 
		    ans=min(ans,findmin(tree[now].lc,l,r));
		if (r>(tree[now].l+tree[now].r)/2)
		    ans=min(ans,findmin(tree[now].rc,l,r));
		return ans;
	}
}

void BinarySearch(int pos,int len,int n) {
	int l=1,r=pos-1;L=pos;
	while (l<=r) {
		int mid=(l+r)/2;
		if (lcp(mid,pos)>=len) L=mid,r=mid-1; else l=mid+1;
	}
	l=pos+1,r=n;R=pos;
	while (l<=r) {
		int mid=(l+r)/2;
		if (lcp(pos,mid)>=len) R=mid,l=mid+1; else r=mid-1;
	}
}

int main() {
	int n,i,ans=1,val,len;
	scanf("%d",&n);
	scanf("%s",s);
	for (i=0;i<n;i++) {
		a[i]=s[i]-'a'+1;
	}
	a[n]=0;
	build(a,sa,n+1,27);
	rmq(n+1);
	num=1;
	buildtree(1,1,n);
	for (i=n-1;i>=0;i--) {
		node now=findval(1,ranki[i]);
		if (now.max==0) val=1,len=1; else {
			val=now.max+1;
			BinarySearch(ranki[i],now.len,n);
			len=now.len+findmin(1,L,R)-i;
		}
		update2(1,ranki[i],i);
		BinarySearch(ranki[i],len,n);
		update1(1,L,R,val,len);
		ans=max(ans,val);
	}
	printf("%d\n",ans);
//	system("pause");
	return 0;
}
