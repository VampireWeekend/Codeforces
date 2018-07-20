#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int main ()
{
	int n,i,k;
	map<int,int> Map;
	for (i=1;i<=n;i++){
		cin >> k;
		Map[k]=i;
	}
	
	for (map<int,int>::iterator iter=Map.begin();iter!=Map.end();iter++)
	{
		cout << *iter << endl;
	}
	return 0;
} 
