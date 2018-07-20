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
const int maxn=100005,inf=0x3f3f3f3f;  
const ld pi=acos(-1.0L);
const ll first=34,second=66,mod=1e18+1,tot=68;
ll len[maxn];

int main() {
	ll n,k,q,i;
	int cnt=0;
	string s="What are you doing at the end of the world? Are you busy? Will you save us?";	
	string t="What are you doing while sending \"\"? Are you busy? Will you send \"\"?";
	len[0]=s.length();
	for (i=1;i<=53;i++) {
		len[i]=len[i-1]*2+68;
	} 
	scanf("%I64d",&q);
	for (i=1;i<=q;i++) {
		scanf("%I64d%I64d",&n,&k);
		for (ll j=n;j>53;j--) {
			if (k<=first) break;
			k-=first;
		}
		if (k<=first) {
			printf("%c",t[k-1]);continue;
		}
		n=min(n,53LL); 
		if (k>len[n]) {
			printf(".");continue;
		}
		while (n) {
			if (k<=first) break;
			if (k>first+len[n-1]&&k<=len[n]-2-len[n-1]) {
				k-=len[n-1];
				break;
			}
			if (k>=len[n]-1) {
				k-=2*len[n-1];break;
			}
			if (k<=first+len[n-1]) k-=first; else k-=len[n-1]+second;
			n--;
		}
		if (n) printf("%c",t[k-1]); else printf("%c",s[k-1]);
	}
	return 0;
}
