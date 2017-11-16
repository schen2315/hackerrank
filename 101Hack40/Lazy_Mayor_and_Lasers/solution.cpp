#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

int n, m;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
	cin >> n;
	long long int h[n+1];
	for(int i=1; i <= n; i++) cin >> h[i];

	cin >> m;
	int xm[m];
	for(int i=0; i < m; i++) cin >> xm[i];
	sort(xm, xm + m);
	long long int ans = 0;
	int cur = 0;
	long long int t = 0;
	for(int i = 1; i <= n; i++) {
		if(i < xm[cur]) {
			t = (-1*i + xm[cur]);
			if(h[i] < t) t = h[i];	
			ans += t;
		} else if(i >= xm[cur]) {
			while(i >= xm[cur] && cur < m-1) cur++;
			if(i >= xm[cur]) ans += h[i];
			else {
				t = (-1*i + xm[cur]);
				if(h[i] < t) t = h[i];	
				ans += t;
			}
		} 
	}
	cout << ans << endl;
    return 0;
}






