#include <cstdio>
#include <iostream>
#include <vector>
#include <string.h>
#include <map>
#include <algorithm>
#include <set>
#include <math.h>
#include <cmath>
#include <queue>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	int ans=0;
	while (n) {
		if (n%2) ans++;
		n/=2;
	}
	cout << ans;
	return 0;
}
