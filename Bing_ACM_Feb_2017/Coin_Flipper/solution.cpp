#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

vector<string> v = {"TTT", "TTH", "THT", "THH", "HTT", "HTH", "HHT", "HHH"};
int seq[8];
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
	int n = 0; cin >> n;
	while(n--) {
		for(int i=0; i < 8; i++) seq[i] = 0;
		int label = 0; string s = "";
		cin >> label >> s;
		string temp;
		for(int i=0; i < 38; i++) {
			temp = s.substr(i, 3);
			for(int j=0; j < v.size(); j++) {
				if(temp == v[j]) seq[j]++;
			}
		}
		cout << label << " ";
		for(int i=0; i < 8; i++) cout << seq[i] << " ";
		cout << endl;
	}
    return 0;
}