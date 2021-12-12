// bellman-ford
#include<iostream>
#include<climits>
using namespace std;
struct Edge 
{
	int source;  
	int destination;  
	int weight;  
};

struct Graph 
{
	int V;        
	int E;        
	struct Edge* edge; 
};

struct Graph* createGraph(int V, int E) 
{
	struct Graph* graph = new Graph;
	graph->V = V;  
	graph->E = E; 
	graph->edge = new Edge[E];
	return graph;
}

void printArr(int arr[], int size) 
{
	cout<<"\n Vertex \t Distance From Source"<<endl;
	for (int i = 0; i < size; i++) 
	{
		cout<<i<<"\t\t";
		cout<<arr[i];
		cout<<endl;
	}
	cout<<endl;
}

void Bellford(struct Graph* graph, int u) 
{
	int V = graph->V;
	int E = graph->E;
	int dist[V];

	for (int i = 0; i < V; i++)
	{
		dist[i] = INT_MAX;
	}
	dist[u] = 0;  // for source dist = 0

	for (int i = 1; i <= V - 1; i++) {
		for (int j = 0; j < E; j++) 
		{
			int u = graph->edge[j].source;
			int v = graph->edge[j].destination;
			int w = graph->edge[j].weight;
			if (dist[u] != INT_MAX && dist[u] + w < dist[v])
			{
				dist[v] = dist[u] + w;
			}
		}
	}

	// for negative cycle
	for (int i = 0; i < E; i++) 
	{
		int u = graph->edge[i].source;
		int v = graph->edge[i].destination;
		int w = graph->edge[i].weight;
		if (dist[u] != INT_MAX && dist[u] + w < dist[v]) 
		{
			cout<<"\n Graph has a negative weight cycle";
			return;
		}
	}

	printArr(dist, V);
	return;
}

int main() 
{
	int vertex;
	int edge;
	cout<<"\n Enter number of edges in graph : ";  
	cin>>edge;
	cout<<"\n Enter number of vertices : ";
	cin>>vertex;
	struct Graph* graph = createGraph(vertex, edge);

	for(int i=0;i<edge;i++)
	{
		cout<<"\n ************* Enter details for edge number "<<i+1<<" ************* :  ";
		cout<<"\n Enter the source vertex : ";
		cin>>graph->edge[i].source;
		cout<<"\n Enter the destination vertex : ";
		cin>>graph->edge[i].destination;
		cout<<"\n Enter the weight : ";
		cin>>graph->edge[i].weight;
		cout<<endl;
	}

	int source_vertex = 0;
	cout<<"\n Enter the source vertex ( by default it is set to 0 ) : ";
	cin>>source_vertex;
  	Bellford(graph, source_vertex); 

  return 0;
}