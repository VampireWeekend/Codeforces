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
const int inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);  
int cnt[10],l[20],r[20];
int lenl,lenr;
ll ans;

inline bool check(int len,bool cl,bool cr) {
	if (len==0||(!cl&&!cr)) return true;
	int j,k;
	if (cl) j=l[len]; else j=0;
	if (cr) k=r[len]; else k=9;
	for (int i=j;i<=k;i++) {
		if (cnt[i]==0) continue;
		cnt[i]--;
		if (check(len-1,cl&&i==l[len],cr&&i==r[len])) {
			cnt[i]++;
			return true;
		}
		cnt[i]++;
	}
	return false;
}

inline void dfs(int num,int len) {
	if (num==9) {
		cnt[num]=len;
		if (check(lenr,1,1)) 
			ans++;
		return;
	}
	for (int i=0;i<=len;i++) {
		cnt[num]=i;
		dfs(num+1,len-i);
	}
} 

int main() {
	ll nl,nr;
	scanf("%I64d%I64d",&nl,&nr);
	mem0(cnt);
	int i;
	lenl=lenr=ans=0;
	while (nl) {
		l[++lenl]=nl%10;
		nl/=10;
	}
	while (nr) {
		r[++lenr]=nr%10;
		nr/=10;
	}
	dfs(0,lenr);
	printf("%I64d\n",ans);
	return 0;
}
