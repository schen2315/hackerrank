#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <cstring>
#include <string>
#include <unordered_map>
using namespace std;


char arr[1000];
unordered_map<string, int> counts = {{"abc", 0}, {"bc", 0}, {"ac", 0}, {"ab", 0}, {"a", 0}, {"b", 0}, {"c", 0}};
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
	int n = 0; cin >> n;
	while(n--) {
		unordered_map<char, int> letter = {{'a',0}, {'b',0}, {'c',0}};
		int label = 0; cin >> label;
		int blocks = 0; cin >> blocks;
		for(int i=0; i < blocks; i++) arr[i] = ' ';
		for(int i=0; i < blocks; i++) cin >> arr[i];
		//for(int i=0; i < blocks; i++) cout << arr[i] << " ";	
		//cout << endl;
		for(int i=0; i < blocks; i++) letter[arr[i]]++;
		//cout << letter['a'] << " " << letter['b'] << " " << letter['c'] << endl;
		int mini = 1e5;
		char minl = 'a';
		//unordered_map<char, int>::iterator = letter.begin();
		for(auto it: letter) {
			//std::cout << it.first << " " << it.second << " ";
			if(it.second < mini) {
				minl = it.first;
				mini = it.second;
			}
		}
		//cout << endl;
		//cout << mini << " " << minl << " " << endl;
		int i=0; 
		string temp = "abc";
		char x[2] = {'a','b'};
		while(arr[i] != ' ') {
			string temp2 = strcat(x,arr + i+1); //+arr[i+2];
			if(temp.compare(temp2) == 0) counts["abc"]++;
			// else if("bc" == (arr[i]+arr[i+1])) counts["bc"]++;
			// else if("ac" == (arr[i]+arr[i+1])) counts["ac"]++;
			// else if("ab" == (arr[i]+arr[i+1])) counts["ab"]++;
			// else if("a" == arr[i]) counts["a"]++;
			// else if("b" == arr[i]) counts["b"]++;
			// else if("c" == arr[i]) counts["c"]++;
		}
	}
    return 0;
}



