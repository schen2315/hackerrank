#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

int arr[25];

long long int F(int n) {
	if(n <= 3) return arr[n];
	return (n)*F(n-1);
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
	int n = 0;
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 3;
	cin >> n;
	cout << F(n) << endl;
	return 0;
}