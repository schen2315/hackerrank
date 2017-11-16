#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
	int n = 0, k = 0;
	cin >> n >> k;
	string s = ""; cin >> s;
	int fr[k];
	for(int i=0; i < k; i++) {
		int t = 0; cin >> t;
		fr[i] = t-1;
	}
	sort(fr, fr+k);
	int x = 0;
	for(int i=0; i < n; i++) {
		if(fr[x] == i && s[i] == '0') {cout << "YES" << endl; return 0;}
		else if(fr[x] == i && s[i] == '1') x++;
	}
	cout << "NO" << endl;
    return 0;
}




