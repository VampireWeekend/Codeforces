#include <cstdio>
#include <iostream>
#include <math.h>
using namespace std;
int n,i,j,sum,k;
long long ans;
struct tree
{
	int maxx,l,r,lc,rc;
};
tree a[500001]; 
int s[100001];

void maketree(int now,int l,int r)
{
	a[now].l=l;a[now].r=r;
    if (l==r)
	{
		a[now].maxx=s[l];
		return;
	}
	else
	{
		sum++;
		a[now].lc=sum;
		maketree(sum,l,(l+r)/2);
		sum++;
		a[now].rc=sum;
		maketree(sum,(l+r)/2+1,r);
		a[now].maxx=max(a[a[now].lc].maxx,a[a[now].rc].maxx);
	}
}

int findmax (int now,int l, int r)
{
	if ((a[now].l>=l)&&(a[now].r<=r)) return a[now].maxx; else
	{
		int mid=(a[now].l+a[now].r)/2;
		if (r<=mid) return findmax(a[now].lc,l,r); else
	        if (l>mid) return findmax(a[now].rc,l,r); else 
	        return max(findmax(a[now].lc,l,r),findmax(a[now].rc,l,r));
	}
}

int main ()
{
	cin >> n;
	sum=1;
	for (i=1;i<=n-1;i++) 
		cin >> s[i];
	maketree(1,1,n);
	ans=0;
	for (i=1;i<=n-1;i++)
	{
		int k=s[i];
		int last=i;
		int z;
		j=1;
		ans+=(long long)(k-i)*j;
		while (k<n)
		{	
			z=k;
			k=findmax(1,last+1,k);
			j++;
			ans+=(long long)(k-z)*j;
			last=z;
		}
	}
	cout << ans << endl;
	return 0;
}
