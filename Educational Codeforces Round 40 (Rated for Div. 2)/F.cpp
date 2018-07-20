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
const int maxn=10005,inf=0x3f3f3f3f,size=3;  
const ll llinf=0x3f3f3f3f3f3f3f3f,mod=1e9+7;   
const ld pi=acos(-1.0L);
ll ac[3];

struct block{
	ll a,p;
	bool f;
};
block b[maxn*2];

bool cmp(block a,block b) {
	return a.p<b.p || (a.p==b.p&&a.f<b.f);
}

struct Matrix {  
    ll a[size][size];  
};  
Matrix ans,p,base;
  
Matrix operator*(const Matrix &x,const Matrix &y) {  
    int i,j,k;  
    Matrix ans;  
    for (i=0;i<size;i++) {  
        for (j=0;j<size;j++) {  
            ans.a[i][j]=0;  
            for (k=0;k<size;k++) {  
                ans.a[i][j]+=x.a[i][k]*y.a[k][j];  
                ans.a[i][j]%=mod;
            }  
        }  
    }   
    return ans;  
}  
  
Matrix fastpower(Matrix base,ll index) {  
    Matrix ans,now;  
    int i,j;  
    for (i=0;i<size;i++) {  
        for (j=0;j<size;j++) {  
            if (i==j) ans.a[i][j]=1; else ans.a[i][j]=0;  
        }  
    }  
    now=base;  
    ll k=index;  
    while (k) {  
        if (k%2) ans=ans*now;  
        now=now*now;  
        k/=2;  
    }  
    return ans;  
}  

void minu(ll i) {
	for (int j=0;j<size;j++)
		p.a[b[i].a][j]=0;
}

void add(ll i) {
	for (int j=0;j<size;j++)
		p.a[b[i].a][j]=base.a[b[i].a][j];
}

int main() {
	ll n,m,i,j,x,y,z;
	scanf("%I64d%I64d",&n,&m);
	for (i=1;i<=n;i++) {
		scanf("%I64d%I64d%I64d",&x,&y,&z);
		b[i*2-1].a=x-1;b[i*2-1].p=y;b[i*2-1].f=1;
		b[i*2].a=x-1;b[i*2].p=z+1;b[i*2].f=0;
	}
	ac[0]=ac[1]=ac[2]=0;
	sort(b+1,b+n*2+1,cmp);
	for (i=0;i<size;i++)
        for (j=0;j<size;j++) {
        	if (i==2&&j==0) p.a[i][j]=0; else 
            if (i==0&&j==2) p.a[i][j]=0; else p.a[i][j]=1;  
            base.a[i][j]=p.a[i][j];
        }
    for (i=0;i<size;i++)
        for (j=0;j<size;j++) 
            if (i!=j) ans.a[i][j]=0; else ans.a[i][j]=1;
	ans=fastpower(p,b[1].p-2)*ans;  
	i=0;
	while (i<n*2) {
		i++;
		if (b[i].f==0) ac[b[i].a]--; else ac[b[i].a]++;
		if (ac[b[i].a]==0) add(i); 
		if (ac[b[i].a]==1&&b[i].f==1) minu(i);
		while (b[i+1].p==b[i].p&&i<n*2) {
			i++;
			if (b[i].f==0) ac[b[i].a]--; else ac[b[i].a]++;
			if (ac[b[i].a]==0) add(i); 
			if (ac[b[i].a]==1&&b[i].f==1) minu(i);
		}
		if (i==n*2) break;
		ans=fastpower(p,b[i+1].p-b[i].p)*ans;
	}
	ans=fastpower(p,m-b[n*2].p+1)*ans;
	ll sum=ans.a[1][1];
	printf("%I64d\n",sum);
	return 0;
}
