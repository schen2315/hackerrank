#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

int heights[26];
int largest = 0;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
	for(int i = 0; i < 26; i++) cin >> heights[i];
	string s = ""; cin >> s;
	for(int i=0; i < s.length(); i++) 
		if(heights[s[i] - 'a'] > largest) largest = heights[s[i] - 'a'];
	cout << largest*s.length() << endl;
    return 0;
}