#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

struct obj {
	long long int val;
	int ind;

	obj(long long int v, int i) {
		val = v;
		ind = i;
	}
};

struct less_than_key
{
    inline bool operator() (const obj& struct1, const obj& struct2)
    {
        return (struct1.val < struct2.val);
    }
};

vector<obj> vec;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n = 0;
    long long int a = 0;
    cin >> n;
	for(int i=1; i <= n; i++) {
		cin >> a;
		vec.push_back(obj(a, i));
	}
	stable_sort(vec.begin(), vec.end(), less_than_key());
	for(int i=0; i < vec.size(); i++) {
		cout << vec[i].ind << " ";
	}
    return 0;
}