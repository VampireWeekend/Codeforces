#include <cstdio>
#include <iostream>
#include <string.h>
#include <string> 
#include <map>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <bitset>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=200005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);
int head[maxn],size[maxn],ms[maxn];
ll ans[maxn],cnt[(1<<20)+5];
int num=0,root=-1,rs=inf,sum;
bool visit[maxn];
char s[maxn];

struct Edge {
	int from,to,pre;
};
Edge edge[maxn*2];

void addedge(int from, int to) {
	edge[num]=(Edge){from,to,head[from]};
	head[from]=num++;
	edge[num]=(Edge){to,from,head[to]};
	head[to]=num++;
}

void getroot(int now,int fa) {
	size[now]=ms[now]=0;
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to]&&to!=fa) {
			getroot(to,now);
			size[now]+=size[to];
			ms[now]=max(ms[now],size[to]);
		}
	}
	size[now]++;
	ms[now]=max(ms[now],sum-size[now]);
	if (ms[now]<rs) root=now,rs=ms[now];
}

void dfs(int now,int fa,int val,int sta) {
	cnt[sta^=(1<<(s[now]-'a'))]+=val;
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to]&&to!=fa) dfs(to,now,val,sta); 
	} 
}

ll cal(int now,int fa,int sta) {
	sta^=(1<<(s[now]-'a'));
	ll ssum=cnt[sta];
	for (int i=0;i<20;i++) 
		ssum+=cnt[sta^(1<<i)];
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to]&&to!=fa) ssum+=cal(to,now,sta); 
	} 
	ans[now]+=ssum;
	return ssum;
}

void solve(int now) {
	visit[now]=1;
	dfs(now,0,1,0); 
	//���㵱ǰ�ڵ㿪ͷ��·���� 
	ll ssum=cnt[0];
	for (int i=0;i<20;i++) 
		ssum+=cnt[1<<i];
	//���㵱ǰ�ڵ����ж��ӷ�֧��������֧�Ĺ��� 
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to]) {
			dfs(to,now,-1,1<<(s[now]-'a'));     //ȥ����ǰ��֧��Ӱ��
			ssum+=cal(to,now,0); 
			dfs(to,now,1,1<<(s[now]-'a'));
		}
	}
	ans[now]+=ssum/2;   //ÿ��·��������������һ�� 
	//��ȥ����ǰ���Ӱ�죬��dfs����û�д���ĵ�
	dfs(now,0,-1,0); 
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to]) {
			root=-1,rs=inf;
			sum=size[to];
			getroot(to,0);
			solve(root);
		}
	}
}

int main() {
	num=0;
	memset(head,-1,sizeof(head));
	int i,j,x,y,n;
	scanf("%d",&n);
	for (i=1;i<n;i++) {
		scanf("%d%d",&x,&y);
		addedge(x,y);
	}
	sum=n;
	getroot(1,0);
	scanf("%s",s+1);
	mem0(visit);
	solve(root);
	for (i=1;i<=n;i++) printf("%I64d ",ans[i]+1);
	return 0;
}
