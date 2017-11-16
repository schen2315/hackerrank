#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
	while(b != 0) {
		a = a%b;
		swap(a,b);
	}
	return a;
}
void extended_gcd(int a, int b, int& x, int& y, int& d) {
	if(b == 0) {
		d = a;
		x = 1;
		y = 0;
	} else {
		extended_gcd(b, a%b, x, y, d);
		int temp = x;
		x = y;
		y = temp - (a/b)*y;
	}
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int x=0; int y=0; int d =0;
	extended_gcd(16,10,x,y,d);
	cout << "The GCD of 16 and 10 is " << d << endl;
	cout << "Coefficients x and y are "<< x <<  " and " << y << endl;
    return 0;
}