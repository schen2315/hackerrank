#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

struct MyV {
	int k = 0;
	int v = 0;
};
struct less_than_key
{
    inline bool operator() (const MyV& struct1, const MyV& struct2)
    {
        return (struct1.v < struct2.v);
    }
};
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
	int N = 0;
	cin >> N;
	MyV orig[N];
	MyV arr[N];
	for(int i=0; i < N; i++) {
		orig[i].k = i;
		cin >> orig[i].v;
		arr[i].v = orig[i].v;
		arr[i].k = i;
	}
	sort(arr, arr+N, less_than_key());
//	for(int i=0; i < N; i++) {
//		cout << arr[i].v << " ";
//	}
//	cout << endl;
//	for(int i=0; i < N; i++) {
//		cout << arr[i].k << " ";
//	}
//	cout << endl;
//	for(int i=0; i < N; i++) {
//		cout << orig[i].k << " ";
//	}
//	cout << endl;
	int largest = 0;
	for(int i = 0; i < N; i++) {
		if(abs(orig[i].k - arr[i].k) > largest) largest = abs(orig[i].k - arr[i].k);
	}
	cout << largest << endl;
    return 0;
}