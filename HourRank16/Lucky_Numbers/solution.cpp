#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int q = 0; cin >> q;
    while(q--) {
    	long long int N = 0; cin >> N;
    	bool ans = false;
    	if(N%4 == 0) ans = true;
    	else if(N%4 == 1 && N>=21) ans = true;
    	else if(N%4 == 2 && N>=14) ans = true;
    	else if(N%4 == 3 && N>=7) ans = true;
    	if(ans) cout << "Yes" << endl;
    	else cout << "No" << endl;
	}
    return 0;
}