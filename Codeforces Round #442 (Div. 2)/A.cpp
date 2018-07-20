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
const int maxn=100005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
string s[15];

int main() {
	int n,k;
	s[1]="Danil";s[2]="Olya";s[3]="Slava";s[4]="Ann";
	s[5]="Nikita";
	string t;
	cin >> t;
	int sum=0;
	for (int i=1;i<=5;i++) {
		string a=t;
		k=0;
		int l=t.length();
		for (int j=0;j+s[i].length()-1<l;j++) {
			if (t.substr(j,s[i].length())==s[i]) k++;
		}
		if (k==1) sum++; else if (k>1) sum+=2;
	}
	if (sum==1) printf("YES"); else printf("NO");
	return 0;
}
