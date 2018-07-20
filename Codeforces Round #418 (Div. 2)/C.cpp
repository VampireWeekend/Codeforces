#include <cstdio>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
char s[1505];
int head[26],tail[26],h[26],val[26];
vector<int> v[26];
vector<int> d[26];
struct DP{
	int cost,value;
} dp[26][562500];

int main() {
	int n,i,q,len,j;
	cin >> n;
	scanf("%s",s);
	memset(head,0,sizeof(head));
	memset(tail,0,sizeof(tail));
	memset(h,0,sizeof(h));
	for (i=0;i<=25;i++) {
		dp[i][0].cost=0;
	}
	len=strlen(s);
	num=s[0]-'a';
	v[num].push_back(0);
	d[num].push_back(1);
	for (i=1;i<len;i++) {
		num=s[i]-'a';
		val[num]++;
		if (s[i]!=s[i-1]) {
			v[num].push_back(i);
			d[num].push_back(1);
		if (!head[num]) {
			head[num]=i;
		} else {
			num=s[i-1]-'a';
			tail[num]=len-i-1;
			int sum=d[num][d[num].size()-1];
			for (j=v[num].size()-2;j>=0;j--) {
				sum+=d[num][j];
				dp[num][++h[num]].cost=i-v[num][j]-sum;
				dp[num][h[num]].value=i-1-v[num][j]+1;
			}
		}
	    } else {
	    	d[num][d[num].size()-1]++;
	    }
	} 
	scanf("%q",q);
	return 0;
}
