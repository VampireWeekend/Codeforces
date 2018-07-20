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
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=300005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);  
bool f[524288];
int num;

struct Tree{
	int l,r;
};
Tree tree[maxn*20];

void insert(int now,int val,int depth) {
	if (depth==21) return;
	if ((val>>(20-depth))%2==1) {
		if (tree[now].l==-1) {
			tree[now].l=++num;
			tree[num].l=tree[num].r=-1;
		}	
		insert(tree[now].l,val,depth+1);
	} else {
		if (tree[now].r==-1) {
			tree[now].r=++num;
			tree[num].l=tree[num].r=-1;
		}
		insert(tree[now].r,val,depth+1);
	}
}

int findxor(int now,int val,int depth) {
	if (depth==21) return 0;
	if ((val>>(20-depth))%2==0) {
		if (tree[now].r!=-1) return findxor(tree[now].r,val,depth+1);
		else return findxor(tree[now].l,val,depth+1)+(1<<(20-depth));
	} else {
		if (tree[now].l!=-1) return findxor(tree[now].l,val,depth+1);
		else return findxor(tree[now].r,val,depth+1)+(1<<(20-depth));
	}
}

int main() {
	int n,m,i,t=0,x,ans;
	scanf("%d%d",&n,&m);
	num=0;
	tree[0].l=tree[0].r=-1;
	mem0(f);
	for (i=1;i<=n;i++) {
		scanf("%d",&x);
		f[x]=1;
	}
	for (i=0;i<=524288;i++) {
		if (!f[i]) insert(0,i,0);
	}
	for (i=1;i<=m;i++) {
		scanf("%d",&x);
		t=t^x;
		ans=findxor(0,t,0);
		printf("%d\n",ans);
	}
	return 0;
}

