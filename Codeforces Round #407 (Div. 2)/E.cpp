#include <cstdio>
#include <iostream>
#include <queue>
#include <set>
#include <string.h>
//������Ũ��Ϊ b �������һ������С��Ũ�� a ��һ���������Ũ�� c ��
//��ô�����Ҫ��b-a���� c �� ��c-b���� a �Ϳ��Եõ�Ũ�� b ����ô�����Ϊ c - a. ���Կ϶�����1000.
using namespace std;
const int maxn=1005;
set<int> st;
int n,k,i,ans,j,f[2*maxn],flag[2*maxn],q[2*maxn],front,rear;

int main () {
	cin >> n >> k;
	memset(f,0,sizeof(f));
	memset(flag,0,sizeof(flag));
	for (i=1;i<=k;i++) {
		scanf("%d",&j);
		flag[j-n+1000]=1;
	}
	rear=0;
	for (i=0;i<=2000;i++) {
		if (flag[i]) {
			if (i-1000==0) {
			cout << 1;
			return 0;
			}
		    rear++;
		    q[rear]=i-1000;
		    f[rear]=1;
		}
	}
	//bfs
	front=0;
    while (front<rear) {
    	front++;
    	int now=q[front];
    	for (i=1;i<=front;i++) {
    		if ((now+q[i]<=1000)&&now+q[i]>=-1000)
    	    	if (!flag[now+q[i]+1000]) {
    		    	k=now+q[i];
    		    	flag[k+1000]=1;
    	     		rear++;
    		    	f[rear]=f[front]+f[i];
    		    	q[rear]=k;
    	    		if (k==0) {
					    cout << f[rear]; 
					    return 0;
					}
    	     	}
    	} 
    }
	cout << -1;
	return 0;
}

/*
100 2
99 200

*/

