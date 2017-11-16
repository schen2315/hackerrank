#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <sstream>
using namespace std;

vector<long double> list;
long double i;
int main() {
    std::string line;
	std::getline(cin, line);
	std::istringstream iss(line);
	while ( iss >> i) {    
		list.push_back(i);
	}
	sort(list.begin(), list.end());
	long double mean = 0;
	for(int i=0; i < list.size(); i++) mean += list[i];
	mean = mean / list.size();
	cout << (int)round(mean) << endl;
	long double median = 0;
	if(list.size() %2 == 0) median = (list[(list.size()/2)-1] + list[(list.size()/2)])/2;
	else median = list[(int)(list.size()/2)];
	cout << (int)round(median) << endl;
	long double mode = 0;
	long double temp = 0;
	int mode_c = 0;
	int temp_c = 0;
	for(int i=0; i < list.size(); i++) {
		temp = list[i];
		temp_c = 1;
		for(int j=i+1; j < list.size(); j++) {
			if(temp == list[j]) temp_c++;
		}
		if(temp_c > mode_c) {
			mode = temp;
			mode_c = temp_c;
		}
	}
	if(mode_c <= 1) cout << endl;
	else cout << (int)round(mode) << endl;
	long double sv = 0;
	for(int i=0; i < list.size(); i++) {
		sv += ((list[i] - mean)*(list[i] - mean));
	}
	sv = sv/(list.size()-1);
	cout << (long int)round(sv) << endl; 
	cout << (long int)round(sqrt(sv)) << endl;
    return 0;
}




