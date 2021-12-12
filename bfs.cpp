#include<iostream>
#include<list>
using namespace std;

class Graph
{
    int Vertex;
    list<int> *adjacency_element;
    public:
    
    Graph(int Vertex){
        this->Vertex=Vertex;
        adjacency_element= new list<int>[Vertex];
    }

    void addEdge(int vertice, int weight){
        adjacency_element[vertice].push_back(weight);
    }
    
    void BFS(int source){
        bool *visited= new bool[Vertex];
        //setting all the vertex to be currently false
        for(int i=0;i<Vertex;i++){
            visited[i]= false;
        }

        list<int> queue;
        visited[source]=true;
        queue.push_back(source);

        list<int>::iterator iterating;
        while(!queue.empty()){
            source=queue.front();
            cout<<source<<" ";
            queue.pop_front();

            for(iterating=adjacency_element[source].begin();iterating!=adjacency_element[source].end();iterating++){
                if(!visited[*iterating]){
                    visited[*iterating]=true;
                    queue.push_back(*iterating);
                }
            }

        }

    }

};

int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    cout<<"For BFS traversal of the graph, the output is: ";
    g.BFS(2);
    
}
