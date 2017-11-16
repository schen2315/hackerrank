#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

int find_min(int N, int * arr);
int change(int num);
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
	int T = 0; cin >> T;
	while(T--) {
		int ans = 0;
		int N = 0; cin >> N;
		int arr[N];
		for(int i=0; i < N; i++) cin >> arr[i]; //, cout << arr[i] << " ";
		//cout << find_min(N, arr) << endl;
		int sum[5];
		int min = find_min(N, arr);
		for(int i=0; i < 5; i++) {
			int dif = 0;
			sum[i] = 0;
			for(int j=0; j < N; j++) {
				dif = arr[j] - min;
				sum[i] += change(dif);
			}
			//cout << sum[i] << " ";
			min--;
		}
		//cout << endl;
		ans = sum[0];
		for(int i=1; i < 5; i++) {
			if(sum[i] < ans) ans = sum[i];
		}
		cout << ans << endl;
	}
    return 0;
}

int find_min(int N, int * arr) {
	int min = arr[0];
	for(int i=1; i < N; i++) {
		if(arr[i] < min) min = arr[i];
	}
	return min;
};
int change(int x) {
	int ret =  x/5 + (x%5)/2 + (x%5)%2;
	return ret;
};





