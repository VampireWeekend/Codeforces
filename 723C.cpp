#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int a[2001],b[2001];

int main ()
{
	int n,m,min,i,ans;
	cin >> n;
	cin >> m;
	min=n/m;
	cout << min << ' ';
	for (i=1;i<=n;i++) b[i]=0;
	for (i=1;i<=n;i++)
	{
		cin >> a[i];
		if (a[i]<=m) b[a[i]]++; else b[0]++;
	}
	for (i=1;i<=m;i++) b[i]-=min;
	int sum=0;
	ans=0;
	for (i=1;i<=m;i++)
	{
		sum+=b[i];
		if (b[i]>0) ans+=b[i];
	}
		ans-=sum; int j=1;
		cout << ans << endl;
		for (i=1;i<=n;i++)
		{
			if (a[i]<=m) 
			{
			if (b[a[i]]<=0) cout << a[i] << ' '; else 
			    if (ans==0) cout << a[i] << ' '; else 
				{
			    	ans--;
			    	while (b[j]>=0) j++;
			    	cout << j << ' ';
			    	b[j]++;
			    }
			} 
			else if (ans==0) cout << a[i] << ' '; else 
				{
			    	ans--;
			    	while (b[j]>=0) j++;
			    	cout << j << ' ';
			    	b[j]++;
			    }
		}
}
