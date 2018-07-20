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
char s[maxn];

struct node {
	int w,p;
};
node a[maxn];

bool cmp(node a,node b) {
	return a.w<b.w;
}

int main() {
	int i,j,n;
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		scanf("%d",&a[i].w);
		a[i].p=i;
	}
	scanf("%s",s+1);
	sort(a+1,a+n+1,cmp);
	stack<int> st;
	queue<int> q;
	for (i=1;i<=n;i++) {
		q.push(a[i].p);
	}
	for (i=1;i<=n*2;i++) {
		if (s[i]=='0') {
			printf("%d ",q.front());
			st.push(q.front());
			q.pop();
		} else {
			printf("%d ",st.top());
			st.pop();
		}
	}
	return 0;
}
