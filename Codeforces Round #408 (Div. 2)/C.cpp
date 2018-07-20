//  http://blog.csdn.net/jeremy1149/article/details/70045015
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
typedef long long ll;
const int maxn=300005;
int a[maxn],visit[maxn];
vector<int> v[maxn];

int main() {
	int n,i,x,y,j,max1,ans,maxi;
	scanf("%d",&n);
	max1=-1<<30;
	if (n==1) {
		scanf("%d",&a[0]);
		cout << a[0];
		return 0;
	}
	for (i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		if (a[i]>max1) {
			max1=a[i];
			maxi=i;
	    }
	}
	int nummax=0,nummax2=0;
	for (i=1;i<=n;i++) {
		if (a[i]==max1) nummax++;
		if (a[i]==max1-1) nummax2++;
	}
	ans=max1+2;
	for (i=1;i<=n-1;i++) {
		scanf("%d%d",&x,&y);
	    v[x].push_back(y);
	    v[y].push_back(x);
    }
    int num;
    if (nummax==1) {
    	num=0;
    	for (i=0;i<v[maxi].size();i++) 
    	    if (a[v[maxi][i]]==max1-1) num++;
        if (num==nummax2) {
        	ans-=2; 
            cout << ans;
            return 0;
        }
    }
    for (i=1;i<=n;i++) {
    	num=0;
    	if (a[i]==max1) num++;
    	for (j=0;j<v[i].size();j++) {
    		if (a[v[i][j]]==max1) num++;
    	}
    	if (num==nummax) {
    		ans--;
    		break;
    	}
    }
    cout << ans;
	return 0;
}
