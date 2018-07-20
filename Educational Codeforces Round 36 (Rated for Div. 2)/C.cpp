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
const int maxn=25,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
char a[maxn],b[maxn],ans[maxn];
int cnt[maxn],cb[maxn];

int main() {
	int i,j,lena,lenb,sa,sb,k,len;
	scanf("%s",a);scanf("%s",b);
	lena=strlen(a),len=lenb=strlen(b); 
	for (i=0;i<lena;i++) cnt[a[i]-'0']++;
	for (i=0;i<lenb;i++) cb[b[i]-'0']++;
	if (lena>lenb) cnt[0]=lenb-lena+cnt[0],lena=lenb;
	if (lena<lenb) {
		for (i=9;i>=0;i--) 
			for (j=1;j<=cnt[i];j++) printf("%d",i);
		return 0;
	}
	if (cnt[b[0]-'0']==0) {
		for (i=b[0]-'0'-1;i>=0;i--) if (cnt[i]!=0) break;
		if (i!=0) printf("%d",i);cnt[i]--;
		for (i=9;i>=0;i--) 
			for (j=1;j<=cnt[i];j++) printf("%d",i);
	} else {
		int flag=0;
		for (i=0;i<len;i++) {
			if (cnt[b[i]-'0']!=0) {
				ans[i]=b[i];cnt[b[i]-'0']--;
			} else {
				for (j=b[i]-'0'-1;j>=0;j--) if (cnt[j]!=0) break;
				if (j<0) {
					flag=1;break;
				}
				ans[i]=(char)(j+'0');cnt[j]--;
			}
		}
		if (!flag) {
			for (i=0;i<len;i++) printf("%c",ans[i]);
		} else {
			for (j=i-1;j>=0;j--) {
				cnt[ans[j]-'0']++;
				for (k=b[j]-'0'-1;k>=0;k--) if (cnt[k]!=0) break;
				if (k>=0) break;
			}
			ans[j]=(char)('0'+k);cnt[k]--;
			for (i=0;i<=j;i++) printf("%c",ans[i]);
			for (i=9;i>=0;i--) 
				for (j=1;j<=cnt[i];j++) printf("%d",i);
		}
	}
	return 0;
}
