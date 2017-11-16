#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;
#define SIZE 105

struct p {
	bool m = false;
	int lcs = 0;
};

int A[SIZE];
int B[SIZE];
p C[SIZE][SIZE];
int n, m;
vector<int> output;
//string output = "";
/*
int LCS(int i, int j) {
	if(i == -1 || j == -1) return 0;
	if(C[i][j] == -1) {
		if(A[i] == B[j]) C[i][j] = LCS(i-1,j-1) + 1;
		else C[i][j] = max(LCS(i-1,j), LCS(i, j-1));
	}
	return C[i][j];
}
*/
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
	cin >> n >> m;
	for(int i=1; i <= n; i++) cin >> A[i];
	for(int i=1; i <= m; i++) cin >> B[i];
	for(int i=0; i < SIZE; i++) {
		for(int j=0; j < SIZE; j++) C[i][j].m = false, C[i][j].lcs = 0;
	}
	//cout << LCS(n-1, m-1) << endl;
	for(int i=1; i <= n; i++) {
		for(int j=1; j <= m; j++) {
			if(A[i] == B[j]) {
				C[i][j].lcs = C[i-1][j-1].lcs + 1;
				C[i][j].m = true;
			}
			else C[i][j].lcs = max(C[i-1][j].lcs, C[i][j-1].lcs);
		}
	}
	/*
	cout << C[n][m].lcs << endl;
	for(int i=0; i <= n; i++) {
		for(int j=0; j <= m; j++) {
			cout << C[i][j].lcs << " ";
		}
		cout << endl;
	}
	*/
	int i=n, j = m;
	int cur = C[i][j].lcs;
	while(cur > 0) {
		if(C[i][j].m) {
			cur = C[i-1][j-1].lcs;
			output.push_back(A[i]);
			i--, j--;
		} else {
			cur = max(C[i-1][j].lcs, C[i][j-1].lcs);
			if(C[i-1][j].lcs > C[i][j-1].lcs) i--;
			else j--;
		}
	}
	for(int i=output.size() - 1; i >= 0; i--) {
		cout << output[i] << " ";
	}
	cout << endl;
	//reverse(output.begin(), output.end());
	//cout << output << endl;
    return 0;
}





