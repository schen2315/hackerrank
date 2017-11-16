#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define m 1000000007
using namespace std;

//function for n! mod m 
long long int nf(long long int n) {
	long long int ans = 1;
	for(int i=3; i <= n; i++) {
		ans = ((ans%m)*(i%m))%m;
	}
	return ans;
}
//function to calculate 
	//modular multiplicative inverse
//modInverse is :
	//
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    //answer is always n/2
    long long int n = 0; cin >> n;
    long long int ans = 1;
    ans = ((n%m)*nf(n))%m;
    cout << ans << endl;
    return 0;
}