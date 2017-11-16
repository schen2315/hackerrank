#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

bool primes[MAX];
int sol[MAX];

void sieve() {
	int n = MAX;
	for(int i=0; i < n; i++) {
		primes[i] = true;
	}
	primes[0] = false;
	primes[1] = false;
	for(int i=2; i < n; i++) {
		if(primes[i]) {
			for(int j=2; i*j < n; j++) {
				primes[i*j] = false;
			}
		}
	}
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    sieve();
    /*
    for(int i=1; i < 100; i++) {
    	if(primes[i]) cout << i << endl;
    }   
	*/ 
    
	for(int i=0; i < MAX; i++) {
		sol[i] = 0;
	}
	int prv = 2;
	sol[2] = 1;
	for(int i=3; i < MAX; i++) {
		if(primes[i]) {
			sol[i] = sol[prv] + 1;
			prv = i;
		} else {
			sol[i] = sol[prv];
		}
	}
	/*
	for(int i=1; i < 100; i++) {
		cout << i << " " << sol[i] << endl;
	}
	*/
	int g = 0; cin >> g;
	while(g--) {
		int n = 0; cin >> n;
		if(sol[n]%2 == 0) {
			cout << "Bob" << endl;
		} else {
			cout << "Alice" << endl;
		}
	}
    return 0;
}






