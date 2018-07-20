#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
const int maxn=1000005;
const int mod=1e9+7;
char c[maxn],p[maxn];

int main() {
	scanf("%s",c);
	strcpy(p,c);
	int len=strlen(c);
	int ans=0;
	int k=1,t=0,r;
	while (r=strstr(p,"bababb")>0) {
		ans-=3;
		for (int i=t;i<=r+3;i++) p[i]='c';
		t=r;
	}
	if (len<=3) {
		if (len==1) cout << 0;
		if (len==2) 
		    if (c[0]=='a'&&c[1]=='b') cout << 1; else cout << 0;
		if (len==3) {
		    if (c[0]=='a'&&c[1]=='b'&&c[2]=='a') cout << 1; else
		    if (c[0]=='a'&&c[1]=='b'&&c[2]=='b') cout << 2; else
		    if (c[0]=='a'&&c[1]=='a'&&c[2]=='b') cout << 3; else
		    if (c[0]=='b'&&c[1]=='a'&&c[2]=='b') cout << 1; else cout << 0;
	    }
	    return 0;
	}
	if (c[0]=='a'&&c[1]=='b') {
		if (c[2]=='a') {
			ans=1;c[1]='a';k=2;
		} 
		if (c[2]=='b') {
			ans=2;c[2]='a';k=2;
		}
	  } 
	while (k+2<len) {
		if (c[k]=='a'&&c[k+1]=='b') {
			if (c[k-1]=='a'&&c[k+2]=='a') {
				ans+=6;
				ans%=mod;
				c[k+1]='a';
			} else
			if (c[k-1]=='a'&&c[k+2]=='b') {
				ans+=6;
				ans%=mod;
				c[k+1]=c[k+2]='a';
			} else
			if (c[k-1]=='b'&&c[k+2]=='a') {
				ans+=1;
				ans%=mod;
				c[k+1]='a';
			} else
			if (c[k-1]=='b'&&c[k+2]=='b') {
				ans+=2;
				ans%=mod;
				c[k+2]='a';
			}
			k++;
		}
		k++;
	}
	if (c[len-2]=='a'&&c[len-1]=='b') {
		if (c[len-3]=='a') {
			ans+=3;
			ans%=mod;
		} 
		if (c[len-3]=='b') {
			ans+=1;
		    ans%=mod;
		}
	  } 
	cout << ans;
	return 0;
}
