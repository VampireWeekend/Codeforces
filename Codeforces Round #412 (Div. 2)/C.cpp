#include <cstdio>
#include <iostream>
#include <algorithm>
#include <math.h> 
using namespace std;
typedef long long ll;

int main() {
	int t,c,i;
	ll x,y,p,q,ans;
	scanf("%d",&c);
	for (i=1;i<=c;i++) {
		scanf("%I64d%I64d%I64d%I64d",&x,&y,&p,&q);
		if ((p==0&&x!=0)||(p==q&&x!=y)) {
			printf("-1\n");
			continue;
		}
		ll qnow=q*((y-q)/q)+q;
	    ll pnow=p*((y-q)/q)+p;
	    if (qnow<y) {
	    	pnow+=p;
	    	qnow+=q;
	    }
	    if (x<pnow) {
	    	ans=qnow-y;
	    	if (x+ans<pnow) 
	    		if ((pnow-x-ans)%(q-p)==0) ans+=(pnow-x-ans)/(q-p)*q;
	    		    else ans+=(pnow-x-ans)/(q-p)*q+q;
	    } else if (x>pnow) {
	    	ans=qnow-y;
	    	if ((x-pnow)%p==0) ans+=(x-pnow)/p*q;
	    		 else ans+=(x-pnow)/p*q+q;
	    } else ans=qnow-y;
		printf("%I64d\n",ans);
	}
	return 0;
}
