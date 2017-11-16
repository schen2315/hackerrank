#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

struct dish {
	int p = 0;
	int d = 0;
	dish(int pi, int di): p(pi), d(di) {}
};
struct comp {
	bool operator() (const dish& d1, const dish& d2) {
		return ((d1.p+d1.d) > (d2.p +d2.d));
	}
};
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
	int n = 0; int k = 0;
	cin >> n >> k;
	vector<dish> arr;
	for(int i=0; i < n; i++) {
		int p = 0, d = 0;
		cin >> p >> d;
		dish t(p,d);
		arr.push_back(t);
	}
	sort(arr.begin(), arr.end(), comp());
	/*
	for(int i=0; i < n; i++) {
		cout << arr[i].p << " " << arr[i].d << endl;
	}
	*/
	long long int ans = 0;
	for(int i=0; i < n; i++) {
		ans -= arr[i].d;
	}
	for(int i=0; i < k; i++) {
		if((ans + arr[i].p + arr[i].d) > ans) ans += (arr[i].p + arr[i].d);
		else break;
	}
	if(ans < 0) ans = 0;
	cout << ans << endl;
    return 0;
}



