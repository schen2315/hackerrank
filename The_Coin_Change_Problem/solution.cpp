#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

long int C[55];
int N, M;

long int NM[255][55];

long int solve(int m, int n) {
	//cout << m << " " << n << " " << NM[n][m] << endl;
	if(m < 0 || n < 0) {
		return 0;
	}
	if(NM[n][m] != -1) return NM[n][m];
	else {
		//cout << m << " " << C[m] << " " << N << endl;
		NM[n][m] = solve(m, n - C[m]) + solve(m-1, n);
		return NM[n][m]; 
	}
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
	cin >> N >> M;
	for(int i=1; i <= M; i++) cin >> C[i];
	for(int i=1; i <= N; i++) NM[i][0] = 0;
	for(int i=0; i <= M; i++) NM[0][i] = 1;
	for(int i=1; i <= N; i++) {
		for(int j=1; j <= M; j++) {
			NM[i][j] = -1;
		}
	}
	cout << solve(M, N) << endl;
	//cout << solve(0, N) << endl;
    return 0;
}