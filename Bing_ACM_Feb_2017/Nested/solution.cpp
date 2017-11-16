#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <sstream>
using namespace std;

struct Nested {
	bool isNested = false;
	vector<Nested*> list;
	Nested* parent = NULL;
	char value;

	Nested(char v) {
		this->value = v;
	}
	Nested(bool n) {
		this->isNested = n;
	}
	~Nested() {
		if(this->isNested) {
			for(int i=0; i < this->list.size(); i++) {
				cout << "deleted this" << endl;
				delete this->list[i];
			}
		}
	}
};	
void print(Nested * root) {
	if(root->isNested) {
		cout << '<';
		for(int i=0; i < root->list.size(); i++) {
			print(root->list[i]);
			if(i != root->list.size()-1) cout << ',';
		}
		cout << '>';
	} else {
		cout << root->value;
	}
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
	string s, query;
	getline(cin, s);
	getline(cin, query);
	Nested *root = new Nested(true);
	Nested *temp = root;
	char val;
	for(int i=1; i < s.length(); i++) {
		if(s[i] == '\'') {
			val = s[++i];
			//cout << val << endl;
			i++;
			temp->list.push_back(new Nested(val));
		} else if(s[i] == '<') {
			Nested* child = new Nested(true);
			child->parent = temp;
			temp->list.push_back(child); 
			temp = child;
		} else if(s[i] == '>') {
			temp = temp->parent;
		}
	}
	//print(root);
	//cout << endl;
	string q;
	istringstream iss(query);
	temp = root;
	while(iss >> q) {
		temp = temp->list[stoi(q)];
		//cout << stoi(q) << " ";
	}
	//cout << temp->list[2]->value << endl;

	if(!temp->isNested) cout << temp->value << endl;
	delete root;
    return 0;
}



