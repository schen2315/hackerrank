#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

int A[2005];
int n, k;

int knap[2005];
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
	int T = 0; cin >> T;
	while(T--) {
		cin >> n >> k;
		for(int i=0; i < n; i++) cin >> A[i];

		sort(A, A+n);
		for(int i=0; i <= k; i++) knap[i] = -1;
		for(int i=0; i < n; i++) knap[A[i]] = A[i];

		knap[0] = 0;
		int temp = 0;
		for(int i=0; i <= k; i++) {
			if(knap[i] == -1) {
				if((i - A[0]) >= 0) {
					knap[i] = knap[i-A[0]] + A[0];
				} else knap[i] = knap[0];
				for(int j=1; j < n; j++) {
					if(i - A[j] >= 0) {
						temp = knap[i-A[j]] + A[j];
					} else temp = knap[0];
					knap[i] = max(temp, knap[i]);
				}
			}
		}
		//for(int i=0; i <= k; i++) cout << knap[i] << " ";
		//cout << endl;
		cout << knap[k] << endl;
	}
    return 0;
}