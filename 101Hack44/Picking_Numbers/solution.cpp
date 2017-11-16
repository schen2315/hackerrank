#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n = 0; cin >> n;
    int ai[100];
    for(int i=0; i < 100; i++) {
    	ai[i] = 0;
    }
    for(int i=0; i < n; i++) {
    	int temp = 0; cin >> temp;
    	ai[temp]++;
    }
   	int ans = ai[1] + ai[2];
    for(int i=2; i < 99; i++) {
    	if(ai[i] + ai[i+1] > ans) {
    		ans = ai[i] + ai[i+1];
    	}
    }  
    cout << ans << endl;
    return 0;
}