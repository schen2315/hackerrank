#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct pr {
	int x = 0;
	int y = 0;
};
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int q = 0; cin >> q;
    while(q--) {
    	int n = 0; cin >> n;
    	//int ux = -1e5, lx = 1e5, uy = -1e5, ly = 1e5;
    	pr* arr = new pr[n];
    	int ux = arr[0].x, lx = arr[0].x, uy = arr[0].y, ly = arr[0].y;
    	for(int i=0; i < n; i++) {
    		cin >> arr[i].x >> arr[i].y;
    	}
    	for(int i=0; i < n; i++) {
    		if(arr[i].x < lx) lx = arr[i].x;
    		if(arr[i].y < ly) ly = arr[i].y;
    		if(arr[i].x > ux) ux = arr[i].x;
    		if(arr[i].y > uy) uy = arr[i].y;
       	}
       	bool ans = true;
       	//cout << ux << " " << lx << " " << uy << " " << ly << endl; 
    	//if(lx == 1e5 || ux == -1e5) cout << "NO" << endl;
    	//else if(ly == 1e5 || uy == -1e5) cout << "NO" << endl;
    	if(lx == ux) cout << "NO" << endl;
    	else if(ly == uy) cout << "NO" << endl;
    	else {
    		for(int i=0; i < n; i++) {
    			if(arr[i].x == ux || arr[i].x == lx) {
    				if(arr[i].y > uy || arr[i].y < ly) {ans = false; break;}
    			} else if(arr[i].y == uy || arr[i].y == ly) {
    				if(arr[i].x > ux || arr[i].x < lx) {ans = false; break;}
    			} else { ans = false; break;}
    		}
    		if(ans) cout << "YES" << endl;
    		else cout << "NO" << endl;
    	}
    	/*
    	for(int i=0; i < n; i++) {
    		cout << arr[i].x << " " << arr[i].y << endl;
    	}
    	*/

    	delete [] arr;
    }
    return 0;
}





