#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N = 0; cin >> N;
    int arr[N];
    for(int i=0; i < N; i++) {
    	cin >> arr[i];
    }
    /*
    for(int i=0; i < N; i++) {
    	cout << arr[i] << " ";
    }
    cout << endl;
    */
    //find smallest
    int sm = 0;
    for(int i=1; i < N; i++) {
    	if(arr[i] < arr[sm]) {
    		sm = i;
    	}
    }
    arr[sm] = 2*arr[sm];
    //cout << arr[sm] << endl;
    int min = arr[0];
    for(int i=1; i < N; i++) {
    	if(arr[i] < min) {
    		min = arr[i];
    	}
    }
    int ans = 0;
    arr[sm] = arr[sm]/2;
    for(int i=0; i < N; i++) {
    	if(arr[sm] == arr[i]) ans++;
    }
    if(ans > 1) {
    	ans = 0;
    	for(int i=0; i < N; i++) {
    		if(2*arr[i] > min) ans++;
    	}
    }
    cout << min << " " << ans << endl;
    return 0;
}






