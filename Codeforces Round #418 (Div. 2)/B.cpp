#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
const int maxn=1005;
int a[maxn],b[maxn],c[maxn],d[maxn];

int main() {
	int n,i,j,top=0;
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		scanf("%d",&a[i]); 
		d[i]=0;
	}
	for (i=1;i<=n;i++) {
		scanf("%d",&b[i]); 
		if (a[i]!=b[i]) c[++top]=i;
	}
	if (top==1) {
		for (i=1;i<=n;i++) {
	    	if (i!=c[1]) d[a[i]]=1;
    	}
    	for (i=1;i<c[1];i++) printf("%d ",a[i]);
    	for (i=1;i<=n;i++) {
	    	if (d[i]==0) {
	    	printf("%d ",i);break;}
    	}
    	for (i=c[1]+1;i<=n;i++) printf("%d ",a[i]);
	}
	else if (top==2) {
		for (i=1;i<=n;i++) {
	    	if (i!=c[1]&&i!=c[2]) d[a[i]]=1;
    	}
    	int i1,i2;
    	i1=i2=0;
    	for (i=1;i<=n;i++) {
	    	if (i!=c[1]&&i!=c[2]) d[b[i]]=1;
    	}
    	for (i=1;i<=n;i++) {
	    	if (d[i]==0) 
			     if (i1!=0) i2=i; else i1=i; 
    	}
    	if (c[1]>c[2]) {
    		int z=c[1];c[1]=c[2];c[2]=z;
    	}
    	if ((a[c[1]]==i1&&b[c[2]]==i2&&b[c[1]]!=i1&&a[c[2]]!=i2)||
		(b[c[1]]==i1&&a[c[2]]==i2&&a[c[1]]!=i1&&b[c[2]]!=i2)) {
    		a[c[1]]=i1;
    		a[c[2]]=i2;
    	} else {
    		a[c[1]]=i2;
    		a[c[2]]=i1;
    	}
		for (i=1;i<=n;i++) printf("%d ",a[i]);
	} 
	return 0;
}
