#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
	long long int n = 0;
	cin >> n;
	long int i = 0;
	while(n != 1) {
		if(n %2 == 0) {
			n = n/2;
		} else {
			n = (3*n) + 1;
		}
		i++;
	}
	cout << i << endl;
    return 0;
}