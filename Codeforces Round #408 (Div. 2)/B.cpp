#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
typedef long long ll;
const int maxn=1000005;
int a[maxn],q,x,y;

int main(){
	int n,m,k,i,pos=1;
	scanf("%d%d%d",&n,&m,&k);
	memset(a,0,sizeof(a));
	for(i=1;i<=m;i++) {
		scanf("%d",&q);
		a[q]=1;
	}
	if (!a[1]) {
		for (i=1;i<=k;i++) {
		scanf("%d%d",&x,&y);
		if (x==pos) 
			pos=y;
		else if (y==pos) 
			pos=x;
		if (a[pos]) break;
	    }
	}
	cout << pos << endl;
	return 0;
}
