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
typedef double db;
const int maxn=70005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
char s[maxn][15];
int num;

struct Tree{ 
    int son[10],val,t; 
	void init() {
		for (int i=0;i<10;i++) son[i]=-1;
		val=t=0;
	}
};
Tree tree[maxn*45]; 

void insert(int now,int n,int i) {
	if (n==10) return;
	tree[now].t=i;
	if (tree[now].son[s[i][n]-'0']==-1) {
		tree[now].son[s[i][n]-'0']=num++;
		tree[num-1].init();
	}
	int p=tree[now].son[s[i][n]-'0'];
	if (tree[p].t!=i) tree[p].val++;
	insert(tree[now].son[s[i][n]-'0'],n+1,i);
}

int findx(int now,int dep,int pos,int i) {
	if (tree[now].val==1) return dep;
	if (pos==10) return inf;
	return findx(tree[now].son[s[i][pos]-'0'],dep+1,pos+1,i);
}

int main() {
	int n,i,j;
	scanf("%d",&n);
	num=1;tree[0].init();
	for (i=1;i<=n;i++) {
		scanf("%s",s[i]+1);
		tree[0].val++;
		for (j=1;j<=9;j++) {
			insert(0,j,i);
		}
	}
	for (i=1;i<=n;i++) {
		int p=0,len=inf;
		for (j=1;j<=9;j++) {
			int f=findx(0,0,j,i);
			if (f<len) {
				len=f;
				p=j;
			}
		}
		len=max(len,1);
		for (j=0;j<len;j++) printf("%c",s[i][j+p]);
		printf("\n");
	}
	return 0;
}

