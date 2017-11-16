#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long long int n = 0, m = 0;
    cin >> n >> m;
    long long int ans1 = (n-1) + (m-1)*n;
    long long int ans2 = (m-1) + (n-1)*m;
    if(ans1 > ans2) cout << ans1 << endl;
    else cout << ans2 << endl;
    return 0;
}