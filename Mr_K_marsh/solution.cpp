#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
#define SIZE 505
using namespace std;
int n, m;
int land[SIZE][SIZE];
int col[SIZE][SIZE];
int row[SIZE][SIZE];

void build() {
	//row
	for(int i=0; i < n; i++) 
		row[i][0] = land[i][0] == 0 ? 0:-1;
	for(int i=0; i < n; i++) {
		for(int j=1; j < m; j++) {
			if(land[i][j] == 0) row[i][j] = row[i][j-1] + 1;
			else row[i][j] = -1;
		}
	}

	for(int i=0; i < m; i++) 
		col[0][i] = land[0][i]==0?0:-1;
	for(int j=0; j < m; j++) {
		for(int i=1; i < n; i++) {
			if(land[i][j] == 0) col[i][j] = col[i-1][j] + 1;
			else col[i][j] = -1;
		}
	}
}
int calc_perim() {
	return 0;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
	cin >> n >> m;
	for(int i=0; i < n; i++) {
		string s = ""; cin >> s;
		for(int j=0; j < s.length(); j++) {
			land[i][j] = s[j] == '.'? 0:-1;
		}
	}	
	build();
	/*
	for(int i=0; i < n; i++) {
		for(int j=0; j < m; j++) {
			cout << row[i][j];
		}
		cout << endl;
	}
	
	for(int i=0; i < n; i++) {
		for(int j=0; j < m; j++) {
			cout << col[i][j];
		}
		cout << endl;
	}
	*/
	int largest = 0;
	for(int i=0; i < n; i++) {
		for(int j = i+1; j < n; j++) {	//every pair of rows
			
			//store all valid columns
			vector<int> v;
			int rdiff = j - i;
			//cout << rdiff << endl;
			for(int k=0; k < m; k++) {
				if(col[j][k] >= rdiff) v.push_back(k);	//k is the col
			} 
			int l=0, r=0;
			//cout << "v "<< v.size() << endl;
			while(r < v.size()) {
				//can a rectangle be formed?
				int cdiff = v[r]-v[l];
				//cout << "r & l " << cdiff << endl;
				//cout << "l "<< v[l] << endl;
				//cout << "r " << v[r] << endl;
				//cout << "cdiff " << cdiff << endl;
				if(row[i][v[r]] - row[i][v[l]] == cdiff 
					&& row[j][v[r]] - row[j][v[l]] == cdiff) {
					if(cdiff > 0)
					largest = max(largest, 2*cdiff+2*rdiff);
				} else {
					while(l < r) l++;
				}
				r++;
			}
		}
	}
	if(largest == 0) cout << "impossible" << endl;
	else cout << largest << endl;
    return 0;
}








