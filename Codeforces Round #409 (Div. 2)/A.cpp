#include <cstdio>
#include <iostream>
using namespace std;
const int maxn=105;
int n,i,ans,flag;
string s;

int main() {
	cin >> s;
	if (s.length()<=1) {
		cout << 0 << endl;
		return 0;
	}
	flag=0;
	for (i=1;i<s.length();i++) {
		if (s[i]=='K') {
			if (s[i-1]=='V') ans++; else {
				if (i>=2) {
			     	if (!flag&&s[i-2]!='V') {
			    		flag=1;
				    	ans++;
			    	}
			    } else if (!flag) {
			    	flag=1;
					ans++;
			    }
			}
		}
		if (s[i]=='V') {
			if (s[i-1]=='V') {
				if (i!=s.length()-1) {
					if (!flag&&s[i+1]!='K') {
				    	flag=1;
				    	ans++;
			    	}
				} else if (!flag) {
					flag=1;
				   	ans++;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
} 
