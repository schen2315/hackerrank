#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct node {
	long dist = 0;
	bool trav = false;
	vector<int> edges;
	vector<int> lengths; 
	int parent = 0;
	int k = 0;
};
void DFS(node* graph, int v) {
	//cout << v << " ";
	//cout << graph[v].dist << endl;
	//cout << graph[v].k << endl;
	graph[v].trav = true;
	for(int i=0; i < graph[v].edges.size(); i++) {
		if(!graph[graph[v].edges[i]].trav) {
			graph[graph[v].edges[i]].parent = v;
			graph[graph[v].edges[i]].dist = graph[v].dist + graph[v].lengths[i];
			graph[graph[v].edges[i]].k = graph[v].k + 1;
			DFS(graph, graph[v].edges[i]);
		}
	}
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    //answer is the sum of all P(A,B)*Dis(A,B)
    	//where P(A,B) is the probability of including route (A,B) in 
		//our calculation
	int n = 0; cin >> n;
    node* graph = new node[n+1];
    for(int i=0; i < (n-1); i++) {
    	int a=0; int b=0; int c=0;
    	cin >> a >> b >> c;
    	graph[a].edges.push_back(b);
    	graph[a].lengths.push_back(c);

    	graph[b].edges.push_back(a);
		graph[b].lengths.push_back(c);    	
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
    //DFS(graph, 2);
    double ans = 0;
    for(int i=1; i <= n; i++) {
    	for(int j=1; j <= n; j++) {
    		graph[j].trav = false;
    		graph[j].parent = 0;
    		graph[j].dist = 0;
    		graph[j].k = 0;
    	}
    	DFS(graph, i);
    	for(int l=i; l <=n; l++) {
    		if(l != i) {
    			double D = 2.0/((graph[l].k - 1) + 2.0);
    			ans += (D*graph[l].dist);
    			//cout << i << " " << l << " " << D << " " << graph[l].dist << endl;
    		}
    	}
    }
    cout << ans << endl;
    return 0;
}