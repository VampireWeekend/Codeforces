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
const int maxn=5005,maxk=26,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int dp[maxn*2],dp2[maxn*2],w[maxn*2],r[maxn*2];
char a[maxn],b[maxn];

class SAM {  
    public:  
    void init() {  
        num=last=0;  
        a[0].len=0;a[0].fa=-1;  
        for (int i=0;i<maxk;i++) a[0].son[i]=-1;  
    }  
    void update (int c) {  
        int now=++num,p;  
        a[now].len=a[last].len+1;  
        memset(a[now].son,-1,sizeof(a[now].son));  
        for (p=last;p!=-1&&a[p].son[c]==-1;p=a[p].fa)  
            a[p].son[c]=now;  
        if (p==-1) a[now].fa=0; else {  
            int q=a[p].son[c];  
            if (a[p].len+1==a[q].len) {  
                a[now].fa=q;  
            } else {  
                int ne=++num;  
                a[ne].len=a[p].len+1;  
                memcpy(a[ne].son,a[q].son,sizeof(a[q].son));  
                a[ne].fa=a[q].fa;  
                for (;p!=-1&&a[p].son[c]==q;p=a[p].fa)   
                    a[p].son[c]=ne;  
                a[q].fa=a[now].fa=ne;  
            }  
        }  
        last=now;  
    }  
    int getnum() {
    	return num;
    }
    int getson(int n,int c) {
    	return a[n].son[c];
    }
    int getfa(int n) {
    	return a[n].fa;
    }
    int getlen(int n) {
    	return a[n].len;
    }
    private:  
    int num,last;  
    struct node{  
        int len,fa;  
        int son[maxk];  
    } a[maxn*2];  
};  
SAM sa,sb;  

int main() {
	scanf("%s",a);
	scanf("%s",b);
	int lena,lenb,i,j,ans;
	lena=strlen(a);lenb=strlen(b);
	sa.init();
	for (i=0;i<lena;i++) {
		sa.update(a[i]-'a');
	}
	int m1=sa.getnum();
    mem0(w);
    for(i=0;i<=m1;i++) w[sa.getlen(i)]++;  
    for(i=0;i<=lena;i++) w[i]+=w[i-1];  
    for(i=m1;i>=0;i--) r[--w[sa.getlen(i)]]=i;  
    int now=0; 
    for (i=0;i<lena;i++) {
		now=sa.getson(now,a[i]-'a');
		dp[now]++;
    }
    for (i=m1;i>0;i--) {
    	int to=sa.getfa(r[i]);
    	if (to!=-1) dp[to]+=dp[r[i]]; 
    }
    
    sb.init();
	for (i=0;i<lenb;i++) {
		sb.update(b[i]-'a');
	}
	int m2=sb.getnum();
    mem0(w);
    for(i=0;i<=m2;i++) w[sb.getlen(i)]++;  
    for(i=0;i<=lenb;i++) w[i]+=w[i-1];  
    for(i=m2;i>=0;i--) r[--w[sb.getlen(i)]]=i;  
    now=0; 
    for (i=0;i<lenb;i++) {
		now=sb.getson(now,b[i]-'a');
		dp2[now]++;
    }
    for (i=m2;i>0;i--) {
    	int to=sb.getfa(r[i]);
    	if (to!=-1) dp2[to]+=dp2[r[i]]; 
    }
    
    ans=inf;
    int u;
	for (i=0;i<lenb;i++) {
		now=u=0;
		for (j=i;j<lenb;j++) {
			now=sa.getson(now,b[j]-'a');
			u=sb.getson(u,b[j]-'a');
			if (now==-1) break;
			if (dp[now]==1&&dp2[u]==1) ans=min(ans,j-i+1);
		}
	}
	if (ans==inf) ans=-1;
	printf("%d\n",ans);
	return 0;
}
