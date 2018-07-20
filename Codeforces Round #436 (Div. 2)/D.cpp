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
#include <deque>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=200005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int a[maxn],cnt[maxn],ch[maxn],st[maxn];

int main() {
	int n,i,s,l;
	s=0;
	scanf("%d",&n);
	mem0(cnt);
	for (i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		if (cnt[a[i]]!=0) s++; 
		cnt[a[i]]++;
		ch[i]=st[i]=0;
	}
	printf("%d\n",s);
	queue<int> q;
	for (i=1;i<=n;i++) {
		if (cnt[i]==0) q.push(i);
		if (cnt[i]>1) ch[i]=1;
	}
	for (i=1;i<=n;i++) {
		if (ch[a[i]]) {
			cnt[a[i]]--;
			if (cnt[a[i]]==0&&!st[a[i]]) continue;
			if (a[i]>q.front()||st[a[i]]) {
				a[i]=q.front();
				q.pop();
			} else {
				st[a[i]]=1;
			}
		}
	}
	for (i=1;i<=n;i++) {
		printf("%d ",a[i]);
	}
	return 0;
}
