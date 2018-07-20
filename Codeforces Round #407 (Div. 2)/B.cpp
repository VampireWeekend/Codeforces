#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
long long b1,q,l,m,k;
int a[100001];
int i;
long long b[10000];

void qsort (int x[],int l,int r) {
	int i,j;
	int mid;
	i=l;
	j=r;
	mid=abs(x[(i+j)/2]);
	int z;
	while (i<j) {
		while(abs(x[i])<mid) i++;
		while(mid<abs(x[j])) j--;
		if (i<=j) {
			z=x[i];x[i]=x[j];x[j]=z;
			i++;j--;
		}
	} 
	if (l<j) qsort(x,l,j);
	if (i<r) qsort(x,i,r);
}

int main () {
	cin >> b1 >> q >> l >> m;
	if (b1==0){
		for (i=1;i<=m;i++) {
    		cin >> a[i];
    		if (a[i]==0) {
    			cout << 0;
    			return 0;
    		}
    	}
		cout << "inf" << endl;
		return 0;
	}
    if (q==0){
    	if (abs(b1)>l) {
		cout << 0 << endl;
		return 0;
	    }
    	int flag1=0,flag2=0;
    	for (i=1;i<=m;i++) {
    		cin >> a[i];
    		if (a[i]==0) 
    			flag1=1;
    		if (a[i]==b1) 
    			flag2=1;
    	}
	    if (flag1&&flag2) cout << 0; else if (flag1) cout << 1; else cout << "inf" << endl; 
		return 0;
	}
	if (q==1) {
		    if (abs(b1)>l)  
{
	cout << 0; return 0;
}	else {
	for (i=1;i<=m;i++) {
    		cin >> a[i];
    		if (a[i]==b1) {
    			cout << 0;
    			return 0;
    		}
    	    }
    	    cout << "inf";
		    return 0;
}		
	}
	if (q==-1) {
		if ((abs(b1)>l)) {
	cout << 0; return 0;
} else {
	   int flag1=0,flag2=0;
	   for (i=1;i<=m;i++) {
    		cin >> a[i];
    		if (a[i]==b1) flag1=1;
    		if (a[i]==-b1) flag2=1;
    		if (flag1&&flag2) {
    			cout << 0;
    			return 0;
    		}
    	    }
    	    cout << "inf";
		return 0;
}
	}
	int ans=0;
	
	if (abs(b1)>l) {
		cout << 0 << endl;
		return 0;
	}
	int k=b1;
	b[1]=b1;
	int num=1;
	while (abs(k*q)<=l) {
		k*=q;
		num++;
		b[num]=k;
	}
	b[num+1]=2100000000;
	for (i=1;i<=m;i++) 
		cin >> a[i];
	
	ans=num;
	qsort(a,1,m);
	int qb=1;
	while (abs(b[qb])<abs(a[1])) qb++;
	if (b[qb]==a[1]) ans--;
	for (i=2;i<=m;i++) {
		if (a[i]!=a[i-1]) {
			while (abs(b[qb])<abs(a[i])) qb++;
        	if (b[qb]==a[i]) ans--;
		}
	}
	cout << ans; 
	return 0;
}
