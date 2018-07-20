#include <cstdio>
#include <iostream>
#include <string.h>
#include <set>
using namespace std;
const int maxn=3e5+5;
typedef long long ll;
char s[15];
int a[maxn],inque[maxn];
set<int> st; 

int main(){
	int n,t,f,top=0,tail=0,ans=0,last=0,p=0;
	scanf("%d",&n);
	memset(inque,0,sizeof(inque));
	for (t=1;t<=2*n;t++) {
		scanf("%s",s);
		if (s[0]=='a') {
			scanf("%d",&f);
			top++;
			last=f;
			inque[f]=1;
			st.insert(f);
			a[top]=f;
		} else {
			tail++;
			st.erase(tail);
			if (last!=tail) {
				ans++;
				last=*(st.begin());
				p=top;
			} else {
				if (tail<p) last=*(st.begin()); else last=a[top-1];
			}
		}
	} 
	cout << ans;
	return 0;
}
