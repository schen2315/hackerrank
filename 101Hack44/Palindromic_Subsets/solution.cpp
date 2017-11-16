#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
#define m (int)(1e9 + 7)
#define UPPER_BOUND (int)(1e5+1)
using namespace std;

struct node {
	int cnt[26] = {0}; 
};
void add(node& n1, node& n2, node& n3) {
	for(int i=0; i < 26; i++) {
		n3.cnt[i] = n1.cnt[i] + n2.cnt[i];
	}
}
void print_node(const node n1) {
	string s = "";
	for(int i=0; i < 26; i++) {
		if(n1.cnt[i] > 0) {
			for(int j=0; j < n1.cnt[i]; j++) {
				string temp = string(1, (char)('a' + i));
				s += temp;
			}
		}
	}
	cout << s;
	//cout << endl;
}

const int N = 1e5;
int pow2[UPPER_BOUND];
int n = 0, q = 0, h = 0;
node S[2*N+1];
int d[N+1];
void compPow2() {
	pow2[0] = 1;	
	for(int i=1; i < UPPER_BOUND; i++) {
		pow2[i] = (pow2[i-1]*2)%m;
	}
}
//function to precompute 2^N up to N=1e5
//node 
	//array len 26
//sum function for nodes
//segment tree
	//store an array S of length 2*N of nodes
	//store an array P of length N for i=0 to N-1 nodes to store k%26, for lazy propogation
//write a build function
//write a modify function -> shift range i,j by t in P
//write a query function 
	//precompute prefix[i], suffix[i]
void print_tree();
void apply(int p, int t) {
	//shift the values in the node
	//store the # of shifts in d[p]%26
	if(t != 0) {
		t = t%26;
		node copy;
		for(int i=0; i < 26; i++) copy.cnt[i] = S[p].cnt[i];
		for(int i=0; i < 26; i++) {
			//int temp = i-t;
			//if(temp < 26) temp += 26;
			//cout << S[p].cnt[(i-t+26)%26] << " ";
			S[p].cnt[i] = copy.cnt[(i-t+26)%26];
		}
		//print_node(S[p]);
		//cout << endl;
		/*
		cout << endl;
		for(int i=0; i < 26; i++) {
			cout << S[p].cnt[i] << " ";
		}
		cout << endl;
		*/
		if(p < n) d[p] += t, d[p] %= 26;
	}
}  
void build() {
	for(int i=n-1; i > 0; i--) add(S[i<<1], S[i<<1|1], S[i]);
}

void build(int p) {
	while(p>1) p >>=1, add(S[p<<1],S[p<<1|1], S[p]);
}

void push(int p) {	
	for(int s=h; s>0; --s) {
		int i = p >> s;
		if(d[i] != 0) {
			apply(i<<1, d[i]);
			apply(i<<1|1, d[i]);
			d[i] = 0;
		}
	}
}
void modify(int l, int r, int t) {
	cout << "mod" << endl;
	cout << l << " " << r << endl;
	assert(l <= r);
	l += n, r+= n;
	cout << "l: " << l << " r: " << r << endl;
	//int l0 = l, r0 = -1;
	int l0 = l, r0 = r;
	for(; l < r; l >>= 1, r >>= 1) {
		if(l&1) {
			cout << "l: " << l << endl;
			apply(l++, t);
		}
		if(r&1) {
			cout << "r: " << r << endl;
			//if(r0 == -1) r0 = r;
			apply(--r, t);
			//print_tree();
		}
	}
	build(l0);
	build(r0 - 1);
	print_tree();
	cout << "mine "; 
	print_node(S[1]);
	cout << endl;
}
int calc_ans(node n1) {
	int sz = 0;
	for(int i=0; i < 26; i++) {
		if(n1.cnt[i]>0) sz++;
	}
	int rg[sz]; int k=0;
	for(int i=0; i < 26; i++) {
		if(n1.cnt[i]>0) rg[k++] = n1.cnt[i];
	}
	/*
	for(int i=0; i < sz; i++) cout << rg[i] << " ";
	cout << endl;
	*/
	int prefix[sz], suffix[sz];
	prefix[0] = pow2[rg[0]-1];	suffix[sz-1] = pow2[rg[sz-1]-1];
	for(int i=1; i < sz; i++) prefix[i] = prefix[i-1]*pow2[rg[i] - 1]%m;
	for(int i=sz-2; i >= 0; i--) suffix[i] = suffix[i+1]*pow2[rg[i] - 1]%m;
	/*
	for(int i=0; i < sz; i++) cout << prefix[i] << " ";
	cout << endl;
	for(int i=sz-1; i >=0; i--) cout << suffix[i] << " ";
	cout << endl;
	*/
	cout << "prefix[sz-1]: " << prefix[sz-1] << endl;
	cout << "suffix[0]: " << suffix[0] << endl;
	int ans = 0;
	for(int i=0; i < sz; i++) {
		//int suf = suffix[i+1]?1:i<sz-1;
		if(i == 0) {
			ans += pow2[rg[i]-1]*suffix[i+1]%m;
		} else if(i == sz-1) {
			ans += prefix[i-1]*pow2[rg[i]-1]%m;
		} else {
			ans += (prefix[i-1]*pow2[rg[i]-1]%m)*suffix[i+1]%m;
		}
	}
	cout << "ans pre prefix: " << ans << endl;
	ans = (ans + prefix[sz-1])%m;
	ans = ans - 1;
	return ans;
}
int query(int l, int r) {
	cout << "query" << endl;
	cout << "l: " << l << " r: " << r << endl;
	assert(l <= r);
	l += n, r += n;
	push(l);
	push(r - 1);
	node total;
	// for(int i=0; i < 26; i++) cout << total.cnt[i] << " ";
	// cout << endl;
	for(; l < r; l >>= 1, r >>= 1) {
		cout << "l: " << l << " r: " << r << endl;
		if(l&1) add(S[l++], total, total)/*, cout << "135" << endl*/;
		if(r&1) add(S[--r], total, total)/*, cout << "136" << endl*/;
	}
	// for(int i=0; i < 26; i++) cout << total.cnt[i] << " ";
	// cout << endl;
	//print_node(total);
	cout << "node: ";
	print_node(total);
	cout << endl;
	return calc_ans(total);
}
void print_tree() {
	for(int i =1; i < 2*n; i++) {
		if(log2(i) == (int)log2(i)) cout << endl;
		print_node(S[i]);
		cout << " ";
	}
	cout << endl;
	for(int i=1; i < 2*n-1; i++) cout << d[i] << " ";
	cout << endl;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    compPow2(); 
	cin >> n >> q;
	h = (int)(log2(2*n-1));
	//h = sizeof(node)* 8 - __builtin_clz(n);
	//cout << "h: " << h << endl;
	string s = ""; cin >> s;
	//cout << s << endl;
	for(int i=0; i < 26; i++) d[i] = 0;
	/*
	for(int i=0; i < 2*n; i++) {
		for(int j=0; j < 26; j++) S[i].cnt[j] = 0;
	}
	*/
	for(int i=0; i < n; i++) {
		S[n+i].cnt[s[i] - 'a'] = 1;
		//print_node(S[n+i]);
	}
	build();
	print_tree();
	//apply(1, 1);
	//print_node(S[1]);
	//print_tree();
	//for(int i=1; i < 2*n; i++) print_node(S[i]);
	cout << "entire string " << s << endl << endl;
	while(q--) {

		int q = 0; cin >> q;
		if(q == 1) {
			int i, j, t; cin >> i >> j >> t;
			modify(i, j+1, t);
			for(int k=i; k <= j; k++ ) s[k] = 'a' + ((s[k] - 'a') + t)%26;
			cout << "entire string " << s << endl << endl;
			//for(int k=0; k < n; k++) push(k+n);
			//for(int i=0; i < n; i++) cout << d[i] << " ";
			//cout << endl;
			//print_tree();
		} else {	//q == 2
			int i, j; cin >> i >> j;
			cout << "ans " << query(i, j+1) << endl;
			cout << "entire string " << s << endl;
			//query(i, j+1);
			print_tree();
		}
		
	}
	/*
	node n1; n1.cnt[0] = 1;
	node n2; n2.cnt[1] = 1;
	node n3;
	add(n1, n2, n3);
	print_node(n3);
	print_node(n1);
	print_node(n2);
	*/
	/*
	for(int i=0; i < UPPER_BOUND; i++) {
		cout << pow2[i] << endl;
	}
	*/
    return 0;
}










