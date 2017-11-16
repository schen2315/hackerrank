#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;
#define SIZE 100
/*
	possible solution
	let us say we are given two sequences, A & B
	A has size n, B has size m, where n <= m
	
	assume for now we have a method for finding the longest subsequence 
	shared by the two starting at some element in A

	we start at the first element of A and find the first match in B
		if we cannot find a match, move on to the 2nd element of A 
		and so on until we find the first match
	call this A_f & B_f
	we iterate from A_f, finding the first match of A_f + i 
	in B that occurs after the previous match and keep track of our 
	current LCS and do this until we reach the end of either array

		No other subsequence occuring after B_f will be longer than our current LCS
			1. No other subsequence starting after B_f (at say A_s) can start before A_f
				-if it did, A_f = A_s
			2. Some other subsequence must start after A_f
			3. therefore we could append A_f to that sequence 
		Now, start at B_0 and try to match subsequences with A either until we reach the 
		end of A or until we reach B_f. If we reach the end of A at B_s, start at B_s and 
		repeat the process
*/
int A[SIZE];
int B[SIZE];
int n, m;

vector<int> A_store[1000];
vector<int> B_store[1000];
int A_p[1000];
int B_p[1000];
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
	cin >> n >> m;
	for(int i=0; i < n; i++) cin >> A[i];
	for(int i=0; i < m; i++) cin >> B[i];
	for(int i=0; i < 1000; i++) {
		A_p[i] = 0;
		B_p[i] = 0;
	}
	for(int i=0; i < n; i++) A_store[A[i]].push_back(i);
	for(int i=0; i < m; i++) B_store[B[i]].push_back(i);
	/*
	for(int i=0; i < 1000; i++) {
		if(A_store[i].size() != 0) {
			cout << i << ": ";
			for(int j=0; j < A_store[i].size(); j++) {
				cout << A_store[i][j] << " ";
			}
			cout << endl;
		}
	}
	cout << endl;
	for(int i=0; i < 1000; i++) {
		if(B_store[i].size() != 0) {
			cout << i << ": ";
			for(int j=0; j < B_store[i].size(); j++) {
				cout << B_store[i][j] << " ";
			}
			cout << endl;
		}
	}
	*/
	int cur;
	int k;
	int val;
	vector<int> longest;
	for(int i=0; i < n; i++) {
		vector<int> temp_l;
		cur = 0;
		/*
		for(int j=0; j < B_store[A[i]].size(); j++) {
			cout << B_store[A[i]][j] << " ";
		}
		*/
		k = i;
		while(cur < m && k < n) {
			val = A[k];
			//cout << i << ": " << cur << endl;
			if(B_store[val].size() != 0) {
				for(int j=0; j < B_store[val].size(); j++) {
					if(B_store[val][B_p[val]] >= cur) {
						temp_l.push_back(val);
						cur = B_store[val][B_p[val]] + 1;
						B_p[val]++;
						break;
					}
					B_p[val]++;
				}
			}
			k++;
		}
		for(int i=0; i < 1000; i++) { A_p[i] = 0; B_p[i] = 0; }
		for(int i=0; i < temp_l.size(); i++) cout << temp_l[i] << " ";
		cout << endl;
		longest = longest.size() > temp_l.size() ? longest : temp_l;
	}
	//cout << longest << endl;
	for(int i=0; i < longest.size(); i++) cout << longest[i] << " ";
	cout << endl;
    return 0;
}





