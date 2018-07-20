#include <cstdio>
#include <iostream>
#include <string.h>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=100005,maxk=26,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;
int w[maxn*20],r[maxn*20];
ll dp[maxn*20];
char s[maxn*10],a[maxn];

class SAM {  
    public:  
    void init() {  
        num=last=0;  
        a[0].len=0;a[0].fa=a[0].flag=-1;  
        for (int i=0;i<maxk;i++) a[0].son[i]=-1;  
    }  
    void update (int c) {  
        int now=++num,p;  
        a[now].len=a[last].len+1;  
        a[now].flag=0;
        memset(a[now].son,-1,sizeof(a[now].son));  
        for (p=last;p!=-1&&a[p].son[c]==-1;p=a[p].fa)  
            a[p].son[c]=now;  
        if (p==-1) a[now].fa=0; else {  
            int q=a[p].son[c];  
            if (a[p].len+1==a[q].len) {  
                a[now].fa=q;  
            } else {  
                int ne=++num;  
                a[ne].flag=0;
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
    int getflag(int n) {
    	return a[n].flag;
    }
	void setflag(int n,int c) {
    	a[n].flag=c;
    }
    private:  
    int num,last;  
    struct node{  
        int len,fa,flag;  
        int son[maxk];  
    } a[maxn*20];  
};  
SAM sa;  

int main() {
	int i,j,len,n,m,ans;
	scanf("%s",s);
	len=strlen(s);
	sa.init();
	for (i=0;i<len;i++) {
		sa.update(s[i]-'a');
	}
	m=sa.getnum();
	mem0(w);
    for (i=0;i<=m;i++) w[sa.getlen(i)]++;  
    for (i=0;i<=len;i++) w[i]+=w[i-1];  
    for (i=m;i>=0;i--) r[--w[sa.getlen(i)]]=i; 
	int now=0; 
    for (i=0;i<len;i++) {
		now=sa.getson(now,s[i]-'a');
		dp[now]++;
	}
	for (i=m;i>0;i--) {
    	int to=sa.getfa(r[i]);
    	if (to!=-1) dp[to]+=dp[r[i]]; 
    }
    scanf("%d",&n);
    for (i=1;i<=n;i++) {
    	scanf("%s",a);
    	int f=strlen(a),c=0;
		now=0;
    	ll ans=0;
    	for (j=0;j<f*2-1;j++) {
    		int ch;
    		if (j<f) ch=a[j]-'a'; else ch=a[j-f]-'a';
    		if (sa.getson(now,ch)==-1) {
    			while (sa.getson(now,ch)==-1&&sa.getfa(now)!=-1) 
    				now=sa.getfa(now);
    			if (sa.getson(now,ch)!=-1) {
    				c=sa.getlen(now)+1;
    				now=sa.getson(now,ch);
    			} else c=0;
    		} else c++,now=sa.getson(now,ch);
    //		if (c>f) c=f;
    		if (j>=f-1&&c>=f) {
    			int p=now;
    			while (p!=0&&sa.getlen(sa.getfa(p))>=f) p=sa.getfa(p);
    			if (sa.getflag(p)<i) ans+=dp[p],sa.setflag(p,i);
    		}
    	}
    	printf("%I64d\n",ans);
    }
	return 0;
}
