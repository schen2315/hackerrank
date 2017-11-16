#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    //look for at the right and left end seats first
    //else look for the first occurence of "EE"
    	//else look for the right most "E"
	string s = "";
	cin >> s;
	int l = s.length();
	if(s[l-1] == 'E') {cout << l-1 << endl;return 0;}
	if(s[0] == 'E') {cout << 0 << endl;return 0;}
	int EE = -1;
	for(int i=0; i < l-1; i++) {
		if(s[i]=='E' & s[i+1]=='E') {
			EE = i+1; break;
		}
	}
	if(EE != -1) cout << EE << endl;
	else {
		for(int i=l-1; i >= 0; i--) {
			if(s[i]=='E') {
				cout << i << endl;
				break;
			}
		}
	}
    return 0;
}

