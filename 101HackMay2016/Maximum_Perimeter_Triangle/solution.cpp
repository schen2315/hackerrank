#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

long int arr[55];
bool degenerate(long int a, long int b, long int c) {
	if((a+b > c) && (a+c > b) && (b+c > a)) return true;
	return false;
}
long int perim(long int a, long int b, long int c) {
	return a+b+c;
}
long int smallest_side(long int a, long int b, long int c) {
	long int ans = min(a, b);
	ans = min(ans, c);
	return ans;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
	int n = 0; cin >> n;
	for(int i=0; i < n; i++) cin >> arr[i];
	//int tot = 0;
	long int maximum = -1;
	for(int i=0; i <= (n-3); i++) {
		for(int j=i+1; j <= (n-2); j++) {
			for(int k=j+1; k <= (n-1); k++) {
				//cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
				//tot++;
				if(degenerate(arr[i], arr[j], arr[k])) {
					if(perim(arr[i], arr[j], arr[k]) > maximum) maximum = perim(arr[i], arr[j], arr[k]);
				}
			}
		}
	}
	if(maximum == -1) {cout << maximum << endl; return 0;}
	//cout << max << endl;
	long int max_side = 0;
	long int min_side = 1e9 + 7;
	for(int i=0; i <= (n-3); i++) {
		for(int j=i+1; j <= (n-2); j++) {
			for(int k=j+1; k <= (n-1); k++) {
				//cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
				//tot++;
				if(degenerate(arr[i], arr[j], arr[k])) {
					//if(perim(arr[i], arr[j], arr[k]) > max) max = perim(arr[i], arr[j], arr[k]);
					if(perim(arr[i], arr[j], arr[k]) == maximum) {
						max_side = max(max_side, arr[i]);
						max_side = max(max_side, arr[j]);
						max_side = max(max_side, arr[k]);
					}
				}
			}
		}
	}

	int count_max = 0;
	int count_min = 0;
	int l1, l2, l3;
	for(int i=0; i <= (n-3); i++) {
		for(int j=i+1; j <= (n-2); j++) {
			for(int k=j+1; k <= (n-1); k++) {
				//cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
				//tot++;
				if(degenerate(arr[i], arr[j], arr[k])) {
					//if(perim(arr[i], arr[j], arr[k]) > max) max = perim(arr[i], arr[j], arr[k]);
					if(perim(arr[i], arr[j], arr[k]) == maximum) {
						if(arr[i] == max_side || arr[j] == max_side || arr[k] == max_side) {
							count_max++;
							l1 = i, l2 = j, l3 = k;
						}
					}
				}
			}
		}
	}
	if(count_max > 1) {
		
		for(int i=0; i <= (n-3); i++) {
			for(int j=i+1; j <= (n-2); j++) {
				for(int k=j+1; k <= (n-1); k++) {
					//cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
					//tot++;
					if(degenerate(arr[i], arr[j], arr[k])) {
						//if(perim(arr[i], arr[j], arr[k]) > max) max = perim(arr[i], arr[j], arr[k]);
						if(perim(arr[i], arr[j], arr[k]) == maximum) {
							min_side = max(min_side, smallest_side(arr[i], arr[j], arr[k]));
						}
					}
				}
			}
		}
		for(int i=0; i <= (n-3); i++) {
			for(int j=i+1; j <= (n-2); j++) {
				for(int k=j+1; k <= (n-1); k++) {
					//cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
					//tot++;
					if(degenerate(arr[i], arr[j], arr[k])) {
						//if(perim(arr[i], arr[j], arr[k]) > max) max = perim(arr[i], arr[j], arr[k]);
						if(perim(arr[i], arr[j], arr[k]) == maximum) {
							if(arr[i] == min_side || arr[j] == min_side || arr[k] == min_side) {
								count_min++;
								l1 = i, l2 = j, l3 = k;
							}
						}
					}
				}
			}
		}

		cout << arr[l1] << " " << arr[l2] << " " << arr[l3] << endl;
	} else {
		cout << arr[l1] << " " << arr[l2] << " " << arr[l3] << endl;
	}
    return 0;
}