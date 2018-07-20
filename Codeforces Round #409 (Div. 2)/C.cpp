#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;
const int maxn=100005;
vector<double> t,ta,tb;

void qsort (double x[],double h[],double s[],int l,int r) {
	int i,j;
	int mid;
	i=l;
	j=r;
	mid=x[(i+j)/2];
	int z;
	while (i<j) {
		while(x[i]<mid) i++;
		while(mid<x[j]) j--;
		if (i<=j) {
			z=x[i];x[i]=x[j];x[j]=z;
			z=h[i];h[i]=h[j];h[j]=z;
			z=s[i];s[i]=s[j];s[j]=z;
			i++;j--;
		}
	} 
	if (l<j) qsort(x,h,s,l,j);
	if (i<r) qsort(x,h,s,i,r);
}

int main() {
	int i,n,pp;
	double sum=0,s,ai,bi;
	double p;
	scanf("%d%d",&n,&pp);
	p=(double) pp;
	s=0;
	for (i=1;i<=n;i++) {
		scanf("%lf%lf",&ai,&bi);
		ta.insert(lower_bound(t.begin(),t.end(),bi/ai)-t.begin()+ta.begin(),ai);
		tb.insert(lower_bound(t.begin(),t.end(),bi/ai)-t.begin()+tb.begin(),bi);
		t.insert(lower_bound(t.begin(),t.end(),bi/ai),bi/ai);
		s+=bi;
	}
	if (s<=p) {
		cout << -1 << endl;
		return 0;
	}
//	qsort(time,a,b,1,n);
	sum=0;
	double mintime=t[0];
  //  double mintime=0;
	for (i=1;i<=n;i++) {
		if (p<=ta[0]) {
			sum=tb[0]/(ta[0]-p);
			cout << setiosflags(ios::fixed) << setprecision(9);
			cout << sum << endl;
			return 0;
		} else {
			int newtb=(p-ta[0])*t[1];
			sum=t[1];
			int time=t[1]+tb[0]/ta[0];
			ta.insert(lower_bound(t.begin(),t.end(),time)-t.begin()+ta.begin(),ta[0]);
			ta.erase(ta.begin());
			tb.insert(lower_bound(t.begin(),t.end(),time)-t.begin()+tb.begin(),newtb);
			tb.erase(tb.begin());
			t.insert(lower_bound(t.begin(),t.end(),time),time);
			t.erase(t.begin());
	//		mintbegin()()=min(mintime,time[i]);
		}
	}
	cout << sum << endl;
	return 0;
}
