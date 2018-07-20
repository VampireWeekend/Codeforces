#include <cstdio>
#include <iostream>
#include <vector>
#include <string.h>
#include <string> 
#include <map>
#include <algorithm>
#include <queue>
#include <math.h>
#include <cmath>
#define mem(a) memset(a,0,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
	int n,i,x,flag=1,y;
	scanf("%d",&n);
	scanf("%d",&x);
	if (n==1) {
		cout << "YES";
		return 0;
	}
	int k=1005;
	for (i=2;i<=n;i++) {
		scanf("%d",&y);
		if (y<=x) {
			if (y==x) {
				flag=2;
				k=i;
				x=y;
				break;
			} else {
				flag=3;
				x=y;
				k=i;
				break;
				if (i==n) {
					cout << "NO";
					return 0;
				}
			}
		}
		x=y;
	}
	if (i==n+1) {
		cout << "Yes";
		return 0;
	}
	if (flag!=3)
	for (i=k+1;i<=n;i++) {
		scanf("%d",&y);
		if (y!=x) {
			if (y<x) {
				flag=3;
				k=i;
				x=y;
				break;
			} else {
				cout << "NO";
		        return 0;
			}
		}
		x=y;
	}
	if (i==n+1) {
		cout << "YES";
		return 0;
	}
	for (i=k+1;i<=n;i++) {
		scanf("%d",&y);
		if  (y>=x) {
				cout << "NO";
		        return 0;
			}
		x=y;
	}
	cout << "YES";
	return 0;
}
