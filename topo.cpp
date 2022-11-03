#include<iostream>
#include <list>
#include <stack>
using namespace std;
class Graph
{
    int V;   
	list<int> *adj;
	void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
	public:
	    Graph(int V);   
	    void addEdge(int v, int w);  
	    void topologicalSort();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack)
{
	visited[v] = true;  
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			topologicalSortUtil(*i, visited, Stack);
	Stack.push(v);
}
 
void Graph::topologicalSort()
{
	stack<int> Stack; 
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;
	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			topologicalSortUtil(i, visited, Stack); 
	while (Stack.empty() == false)
	{
		cout << Stack.top() << " ";
		Stack.pop();
	}
}
 
int main()
{
	int v1,v2,n,e;
	cout<<"\nEnter number of vertices: ";
	cin>>n;
	Graph g(n);
	cout<<"\nEnter number of edges: ";
	cin>>e;
		
	for(int i=0; i<e; i++) {
		cout<<"\nEnter edge number "<<i+1<<": ";
		cin>>v1>>v2;
		g.addEdge(v1,v2);
	}
 
	cout << "Following is a topological sort of the given graph: ";
	g.topologicalSort(); 
	return 0;
}