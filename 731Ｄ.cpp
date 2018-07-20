#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	int n,c,j,i,k;
	int len,lenn,len3;
	bool z=true;
	int equ=1;
	int w[5001];
	int w2[5001];
	int w3[5001];
	cin >> n;
	cin >> c;
	cin >> len;
	for (i=1;i<=len;i++) cin >> w[i];
	for (i=2;i<=n;i++)
	{
		cin >> lenn;
		cin >> w2[1];
		j=1;
		while ((w[j]==w2[j])&&(j<lenn)&&(j<len))
		{
			j++;
			cin >> w2[j];
		}
		if ((w[j]==w2[j])&&(len==lenn)) equ++; else
		if ( (w[j]>w2[j]) || ((w[j]==w2[j])&&(len>lenn)) )  
		{
			equ=false;
			if (z) 
			{
				z=false;
				while (j<lenn){ j++;cin >> w2[j];}
				for (k=1;k<=len;k++) w3[k]=w[k];
				len3=len;
				for (k=1;k<=lenn;k++) w[k]=w2[k];len=lenn;
			} else {
				cout << -1 << endl;
				return 0;
			}
		}
		while (j<lenn){ j++;cin >> w2[j];}
	}
	if (equ==n) cout << 0 << endl; else if (equ!=1) cout << -1 << endl; else
	if (not z)
	{
	    while (j<lenn){ j++;cin >> w2[j];
	    }
	    j=1;
		while ((w3[j]==w2[j])&&(j<lenn)&&(j<len3))
			j++;
		if ((w[j]>w3[j])||((w[j]==w3[j])&&(lenn>len3))) cout << -1 << endl;
		else cout << c-w3[1]+1 << endl;
    } else cout << 0 << endl;
    return 0;
}
