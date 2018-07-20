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
const int maxn=400005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
ll sum[maxn][21],a[maxn];
int fa[maxn][21];
int n=0;

int main() {
	int last=0,q,i,j;
	ll x,y,z;
	scanf("%d",&q);
	memset(fa,-1,sizeof(fa));
	meminf(sum);
	sum[1][0]=a[1]=0;n=1;
	for (j=1;j<=q;j++) {
		scanf("%I64d",&z);
		scanf("%I64d%I64d",&x,&y);
		x^=last;y^=last;
		if (z==1) {
			n++;a[n]=y;
			if (a[x]>=y) {
				fa[n][0]=x;
			} else {
				int now=x;
				for (i=20;i>=0;i--) {
					if (fa[now][i]==-1) continue;
					if (a[fa[now][i]]<y) now=fa[now][i];
				}
				fa[n][0]=fa[now][0];
			}
			int now=fa[n][0];
			if (now==-1) continue;
			sum[n][0]=a[now];
			for (i=1;i<=20;i++) {
				if (fa[now][i-1]==-1) break;
				fa[n][i]=fa[now][i-1];
				sum[n][i]=sum[n][i-1]+sum[now][i-1];
				now=fa[now][i-1];
			}
		} else {
			int ans=1;
			if (a[x]>y) {
				printf("0\n");last=0;
				continue;
			} else y-=a[x]; 
			int now=x;
			for (i=20;i>=0;i--) {
				if (fa[now][i]==-1) continue;
				if (sum[now][i]<=y) {
					ans+=(1<<i);
					y-=sum[now][i];
					now=fa[now][i];
				}
			}
			printf("%d\n",ans);
			last=ans;
		}
	}
	return 0;
}
