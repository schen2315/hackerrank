#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
#define SIZE 10000
using namespace std;

int N, lenA, lenB;
string A, B;

int D[SIZE][SIZE];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
	cin >> N;
	while(N--) {
		cin >> A >> B;
		lenA = A.length();
		lenB = B.length();
		D[0][0] = 0;
		for(int i=1; i <= lenA; i++) D[i][0] = i;
		for(int j=1; j <= lenB; j++) D[0][j] = j;

		for(int i=1; i <= lenA; i++) {
			for(int j=1; j <= lenB; j++) {
				D[i][j] = min(A[i-1] == B[j-1] ? D[i-1][j-1] : D[i-1][j-1] + 1, D[i-1][j]+1);
				D[i][j] = min(D[i][j], D[i][j-1]+1);
			}
		}
		cout << D[lenA][lenB] << endl;
	}
    return 0;
}



