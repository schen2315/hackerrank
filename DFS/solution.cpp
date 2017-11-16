#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


struct node {
	int dist = 0;
	bool trav = false;
	vector<int> edges;
	//vector<int> lengths; 
};
void DFS(node* graph, int v) {
	graph[v].trav = true;
	for(int i=0; i < graph[v].edges.size(); i++) {
		if(!graph[graph[v].edges[i]].trav) DFS(graph, graph[v].edges[i]);
	}
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n = 0; cin >> n;
    node* graph = new node[n+1];
    for(int i=0; i < (n-1); i++) {
    	int a=0; int b=0; int c=0;
    	cin >> a >> b >> c;
    	graph[a].edges.push_back(b);
    	//graph[a].lengths.push_back(c);

    	graph[b].edges.push_back(a);
		//graph[b].lengths.push_back(c);    	
    }
    /*
    for(int i=1; i <= n; i++) {
    	cout << i << endl;
    	for(int j=0; j < graph[i].edges.size(); j++) {
    		cout << graph[i].edges[j] << " " << graph[i].lengths[j] << endl;
    	}
    	cout << endl;
    }
    */
    return 0;
}









