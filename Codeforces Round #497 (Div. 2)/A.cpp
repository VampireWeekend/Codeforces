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
#define pb push_back 
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=100005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
char s[maxn];

int main() {
	scanf("%s",s+1);
	int n=strlen(s+1),i,j;
	set<char> st;
	st.insert('a');st.insert('e');st.insert('i');st.insert('o');st.insert('u');
	for (i=1;i<=n;i++) {
		if (s[i]=='n') continue;
		if (st.count(s[i])) continue;
		if (i==n||!st.count(s[i+1])) {
			printf("no");
			return 0;
		}
	}
	printf("yes");
	return 0;
}
