#include <cstdio> 
#include <iostream>
#include <string.h>
using namespace std;
int a[10],b[10],c[10],d[10],max,min,i,j;

int main () {
	int n,k;
    char ch;
    cin >> n;
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    for (i=1;i<=n;i++) {
    	cin >> ch;
    	k=(int)ch-48;
    	b[k]++;
    	c[k]++;
    }
    memset(a,0,sizeof(a));
    memset(d,0,sizeof(d));
    for (i=1;i<=n;i++) {
    	cin >> ch;
    	k=(int)ch-48;
    	a[k]++;
    	d[k]++;
    }
    for (i=0;i<=9;i++) {
    	for (j=i;j<=9;j++) {
    	    if ((a[j]!=0)&&(b[j-i]!=0)) {
    	    	if (a[j]-b[j-i]>0) {
    	    		a[j]-=b[j-i];
    	    		b[j-i]=0;
    	    	} else {
    	    		b[j-i]-=a[j];
    	    		a[j]=0;
    	    	}
    	    }  
    	}
    }
    int sum=0;
    for (i=0;i<=9;i++) {
    	sum+=a[i];
    }
    cout << sum << endl;
    
    for (i=0;i<=9;i++) {
    	a[i]=d[i];
    	b[i]=c[i];
    }
    
	for (i=1;i<=9;i++) {
    	for (j=i;j<=9;j++) {
    	    if ((a[j]!=0)&&(b[j-i]!=0)) {
    	    	if (a[j]-b[j-i]>0) {
    	    		a[j]-=b[j-i];
    	    		b[j-i]=0;
    	    	} else {
    	    		b[j-i]-=a[j];
    	    		a[j]=0;
    	    	}
    	    }  
    	}
    }
    sum=0;
    for (i=0;i<=9;i++) {
    	sum+=a[i];
    }
    cout << n-sum << endl;
    return 0;
}
