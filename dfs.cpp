#include <iostream>
#include <conio.h>
#include <list>
#include <stack>
#include <vector>
using namespace std;
class Graph
{
    int V;
    list<int> *l;
public:
    Graph(int v)
    {
        V = v;
        l = new list<int>[V];
    }
    void addEdge(int u, int v, bool undir = true)
    {
        l[u].push_back(v);
        if (undir)
            l[v].push_back(u);
    }
    vector<int> dfs(int source)
    {
        stack<int> s;
        bool *visited = new bool[V]{0};
        vector<int> ans;
        s.push(source);

        while (!s.empty())
        {
            int ele = s.top();
            s.pop();
            if (!visited[ele])
            {
                ans.push_back(ele);
                visited[ele] = true;
            }
            for (int nbr : l[ele])
                if (!visited[nbr])
                    s.push(nbr);
        }
        return ans;
    }
    // void printAdjList()
    // {
    //     for (int i = 1; i < V; i++)
    //     {
    //         cout << i << " -> ";
    //         for (int nbr : l[i])
    //             cout << nbr << ", ";
    //         cout << endl;
    //     }
    // }
};
int main()
{
    cout << "<--- Depth First Search --->" << endl
         << endl;
    Graph g(7);
    char arr[] = {' ', 'A', 'B', 'C', 'D', 'E', 'F'};
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(1, 6);
    g.addEdge(2, 3);
    g.addEdge(2, 5);
    g.addEdge(3, 4);
    g.addEdge(3, 6);
    g.addEdge(4, 1);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    vector<int> ans = g.dfs(4);
    for (int i = 0; i < ans.size(); i++)
        cout << arr[ans[i]] << " -> ";
    // cout << endl
    //      << endl;
    // g.printAdjList();
    getch();
    return 0;
}

