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
#define N 32000
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=105,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int a[N],b[maxn];
bool prime[N];
int num;
map<int,int> sg;

void init() {
	num=0;
	mem0(prime);
	int i,j;
	for (i=2;i<=N;i++) {
		if (!prime[i]) 
			a[++num]=i;
		for (j=1;j<=num&&i*a[j]<=N;j++) {
			prime[i*a[j]]=1;
			if (i%a[j]==0) 
				break;
		}
	}
}

int getsg(int state) {
	if (state==0) return 0;
	if (sg[state]) return sg[state];
	int i;
	bool visit[100];
	mem0(visit);
	for (i=1;i<=31&&(state>>i-1)>0;i++)  
		visit[getsg((state>>i)|(state&((1<<i-1)-1)))]=1;
	for (i=0;;i++)
		if (!visit[i]) 
			return sg[state]=i;
}

int main() {
	init();
	int n,i,j,x,state,y=-1;
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		scanf("%d",&b[i]);
		y=max(y,b[i]);
	}
	int sum=0;
	for (i=1;i<=num&&a[i]*a[i]<=y;i++) {
		state=0;
		for (j=1;j<=n;j++) {
			int cnt=0;
			while (b[j]%a[i]==0) {
				cnt++;
				b[j]/=a[i];
			}
			if (cnt) state=state|(1<<cnt-1);
		}
		sum=sum^getsg(state);
	}
	for (i=1;i<=n;i++) {
		if (b[i]==1) continue;
		sum=sum^getsg(1);
		int p=b[i];
		for (j=1;j<=n;j++)
			while (b[j]%p==0) b[j]/=p;
	}
	if (sum) cout << "Mojtaba"; else cout << "Arpa";
	return 0;
}

