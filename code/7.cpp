#include <bits/stdc++.h>
using namespace std;

class Graph {
	int v;
	int e;
	int** adj;

public:
	Graph(int v, int e);
	void addEdge(int start, int e);
	void DFS(int start, vector<bool>& visited);
};

Graph::Graph(int v, int e)
{
	this->v = v;
	this->e = e;
	adj = new int*[v];
	for (int row = 0; row < v; row++) {
		adj[row] = new int[v];
		for (int column = 0; column < v; column++) {
			adj[row][column] = 0;
		}
	}
}

void Graph::addEdge(int start, int e)
{
	adj[start][e] = 1;
	adj[e][start] = 1;
}

void Graph::DFS(int start, vector<bool>& visited)
{
	cout << start << " ";
	visited[start] = true;
	for (int i = 0; i < v; i++) {
		if (adj[start][i] == 1 && (!visited[i])) {
			DFS(i, visited);
		}
	}
}

int main()
{
	int v, e;
    cout << "Enter number of nodes and edges: ";
    cin>>v>>e;

	Graph G(v, e);

    int a,b;
    for(int i=0;i<e;i++){
        cout << "Enter nodes joined by edge: ";
        cin>>a>>b;
        G.addEdge(a,b);
    }
	vector<bool> visited(v, false);

    int s;
    cout << "Enter starting node: ";
    cin>>s;
    
    cout << "Nodes are visited as follows: ";

	G.DFS(s, visited);
}
