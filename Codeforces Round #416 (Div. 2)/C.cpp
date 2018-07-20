#include <cstdio>
#include <iostream>
#include <string.h>
#include <set>
using namespace std;
const int maxn=5005;
int head[maxn],tail[maxn];
int a[maxn],dp[maxn],mark[maxn],q[maxn];

int main () {
	int n,i,j;
	scanf("%d",&n);
	memset(head,0,sizeof(head));
    for (i=1;i<=n;i++) {
    	scanf("%d",&a[i]);
    	if (!head[a[i]]) head[a[i]]=i;
    	tail[a[i]]=i;
    }
    dp[0]=0;
    for (i=1;i<=n;i++) {
    	if (tail[a[i]]==i) {
    		dp[i]=dp[i-1];
			j=i+1;
    		memset(mark,0,sizeof(mark));
    		int valid=0,cnt=0;
    		int now=0,h=0,t=0,k;
    		while (tail[a[j-1]]<=i&&j>1) {
    			j--;
    			if (!mark[a[j]]) {
    				cnt++;
    			    mark[a[j]]=1;
    			}
    			if (j==head[a[j]]) {
    				valid++;
    				q[++t]=a[j];
    			}
    			if (valid==cnt) {
    				for (k=h+1;k<=t;k++) now=now^q[k];
    				h=t;
    				dp[i]=max(dp[i],now+dp[j-1]);
    			}
    		}
    	} else {
    		dp[i]=dp[i-1];
    	}
    }
    cout << dp[n];
	return 0;
}
