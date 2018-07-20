#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int c[200001];
int f[200001];
int set[200001];
vector<int> v[200001];

int find(int a){
	if (f[a]==a) return a; else {
    	f[a]=find(f[a]);
    	return f[a];
    }
}

void unify(int l,int r)
{
	int lf,rf;
	lf=find(l);
	rf=find(r);
	f[lf]=rf;
}

int main()
{
	int n,m,k,i,ans,l,r,j;
	cin >> n >> m >> k;
	for (i=1;i<=n;i++) {
		cin >> c[i];
		f[i]=i;
	}
	for (i=1;i<=m;i++) 
	{
		cin >> l;	
		cin >> r;
		unify(l,r);
	}  
	int top=0;	
	for (i=1;i<=n;i++) {
		if (f[i]==i) {
			top++;
			set[i]=top;
		}
	}
	for (i=1;i<=n;i++) 
	{
		v[set[find(i)]].push_back(c[i]);
	}
	ans=0;
	map<int,int> Map;
	for (i=1;i<=top;i++) {
		int size=v[i].size();
		int max=0;
		for (j=0;j<size;j++) {
			Map[v[i][j]]++;
			if (Map[v[i][j]]>max) max=Map[v[i][j]];
		}
		ans+=(size-max);
		Map.clear();
	}
	cout << ans << endl;
	return 0;
}
