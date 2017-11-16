#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

struct interval {
	int st = 0;
	int et = 0;
};
bool comp(interval e1, interval e2) {
	return e1.et < e2.et;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
	int n = 0; cin >> n;
	interval* arr = new interval[n];
	for(int i=0; i < n; i++) {
		int st = 0, et = 0;
		cin >> st >> et;
		arr[i].st = st;
		arr[i].et = et;
	}
	sort(arr, arr + n, comp);
	/*
	for(int i=0; i < n; i++) {
		cout << arr[i].et << " ";
	}
	cout << endl;
	*/
	int start = 0;
	int ans = 0;
	for(int i=0; i < n; i++) {
		if(arr[i].st >= start) {
			ans++;
			start = arr[i].et;
		}
	}
	delete [] arr;
	cout << ans << endl;
    return 0;
}





