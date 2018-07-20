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
const int maxn=200005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int pre[maxn];
char s[maxn];
vector<int> v[maxn];

int main() {
	int len,i,j;
	scanf("%s",s+1);
	len=strlen(s+1);
	queue<int> a,b;
	for (i=1;i<=len;i++) {
		if (s[i]=='1') {
			if (a.empty()) {
				printf("-1");
				return 0;
			}
			pre[i]=a.front();a.pop();
			b.push(i);
		} else {
			if (!b.empty()) {
				pre[i]=b.front();b.pop();
			} else pre[i]=-1;
			a.push(i);
		}
	}
	if (!b.empty()) {
		printf("-1");
		return 0;
	}
	int ans=a.size();
	printf("%d\n",ans);
	stack<int> st;
	while (!a.empty()) {
		int now=a.front();
		a.pop();
		int cnt=0;
		st.push(now);cnt++;
		while (pre[now]!=-1) {
			now=pre[now];
			st.push(now);
			cnt++;
		}
		printf("%d ",cnt);
		while (!st.empty()) {
			printf("%d ",st.top());
			st.pop();
		}
		printf("\n");
	}
	return 0;
}
