#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5;
int n = 0;
int t[2*N];
int h = 0;
int d[N];
/*
void build() {
	for(int i=n-1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];	
}

void modify(int p, int value) {
	for(t[p += n]=value; p > 1; p >>= 1) t[p >> 1] = t[p] + t[p^1];
}
int query(int l, int r) {
	int res = 0;
	for(l += n, r+= n; l < r; l >>= 1, r >>= 1) {
		if(l&1) res += t[l++];
		if(r&1) res += t[--r];
	}
	return res;
}

void modify(int l, int r, int value) {
	for(l+=n, r+=n; l <r; l >>= 1, r >>= 1) {
		if(l&1) t[l++] += value;
		if(r&1) t[--r] += value;
	}
}
int query(int p) {
	int res = 0;
	for(p += n; p > 0; p >>= 1) res += t[p];
	return res;
}
void push() {
  for (int i = 1; i < n; ++i) {
    t[i<<1] += t[i];
    t[i<<1|1] += t[i];
    t[i] = 0;
  }
}
*/
/*
void build() {
	for(int i=n-1; i > 0; --i) t[i] = max(t[i<<1], t[i<<1|1]);
}
void apply(int p, int value) {		//increm value + store info in border leaves
	t[p] += value;
	if(p < n) d[p] += value;
}
void build(int p) {					//propogate changes up the tree
	while(p > 1) p >>= 1, t[p] = max(t[p<<1], t[p<<1|1]) + d[p];
}
void push(int p) {					//propogate changes down the tree
	for(int s=h; s>0; --s) {
		int i = p >> s;			//start at top of tree, work our way down
		if(d[i] != 0) {
			apply(i<<1, d[i]);
			apply(i<<1|1, d[i]);
			d[i] = 0;
		}
	}
}
void inc(int l, int r, int value) {
	l += n, r += n;
	int l0 = l, r0 = r;
	for(; l < r; l >>= 1, r >>= 1) {	//increment only at the border
		if(l&1) apply(l++, value);
		if(r&1) apply(--r, value);
	}
	build(l0);							//propogate changes up
	build(r0 - 1);
}
int query(int l, int r) {
	l += n, r += n;
	push(l);							//propogate changes down
	push(r - 1);
	int res = -2e9;
	for(; l < r; l >>= 1, r >>= 1) {	//
		if(l&1) res = max(res, t[l++]);
		if(r&1) res = max(res, t[--r]);
	}
	return res;
}
*/ 
void calc(int p, int k) {
	if(d[p] == 0) t[p] = t[p<<1] + t[p<<1|1];
	else t[p] = d[p]*k;		//I think if we wanted to modify by adding, we 
							//would do t[p] += d[p]*k
}
void apply(int p, int value, int k) {
	t[p] = value * k;
	if(p < n) d[p] = value;
}
void build(int l, int r) {
	int k=2;
	for(l += n, r += n-1; l > 1; k <<= 1) {
		l >>= 1, r >>= 1;
		for(int i=r; i >= l; --i) calc(i, k);
	}
}
void push(int l, int r) {
	int s = h, k = 1 << (h-1);
	for(l += n, r += n-1; s > 0; --s, k >>= 1) {
		for(int i = l >> s; i <= r >> s; ++i) if(d[i] != 0) {
			apply(i<<1, d[i], k);
			apply(i<<1|1, d[i], k);
			d[i] = 0;
		}
	}
}
void modify(int l, int r, int value) {
	if(value == 0) return;
	push(l, l+1);			//propogate changes down before modifying
	push(r-1, r);
	int l0 = l, r0 = r, k = 1;
	for(l += n, r += n; l < r; l >>= 1, r >>= 1, k <<= 1) { //why do we multiply k by 2 every time
		if(l&1) apply(l++, value, k);		//actually modifies the value
		if(r&1) apply(--r, value, k);
	}
	build(l0, l0+1);						//apply changes going up the tree
	build(r0 - 1, r0);
}
int query(int l, int r) {
	push(l, l+1);				//propogate the changes down
	push(r-1, r);
	int res = 0;
	for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if(l&1) res += t[l++];	//accumulate sum from only the necessary nodes
		if(r&1) res += t[--r];
	}	
	return res;
}
void print() {
	for(int i=1; i < 2*n; i++) {
		if(log2(i) == (int)log2(i)) cout << endl;
		cout << t[i] << " ";
	}
	cout << endl;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
	cin >> n;
	h = sizeof(int) * 8 - __builtin_clz(n);
	//cout << h << endl;
	for(int i=0; i < n; i++) {
		cin >> t[n+i];
	}
	
	build(0, n);
	print();
	/*
	modify(3,11,2);
	push();
	cout << query(4) << endl;
	*/
	//modify(0, 10);
	//cout << query(0,2) << endl;
	/*
	print();
	cout << "max: " << query(1,6) << endl;
	inc(1,6,2);
	print(); 
	cout << "max: " << query(2,4) << endl;
	print();
	*/
    return 0;
}




