#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> edgeWeightPair;
class Graph
{
    int V;
    list<edgeWeightPair> *adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<edgeWeightPair>[V];
    }

    void addEdge(int u, int v, int w)
    {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    void printNeighbour(int chk)
    {
        cout << chk << ": ";
        for (auto i = adj[chk].begin(); i != adj[chk].end(); i++)
        {
            cout << "(" << i->first << ", " << i->second << ")"
                 << " ";
        }
    }

    void BFS(int source)
    {
        vector<bool> visited(V, false);
        queue<int> Q;
        visited[source] = true;
        // cout << source << " ";
        Q.push(source);

        while (!Q.empty())
        {
            int u = Q.front();
            cout << u << " ";
            Q.pop();
            for (auto element : adj[u])
            {
                int v = element.first;
                if (visited[v] != true)
                {
                    visited[v] = true;
                    Q.push(v);
                }
            }
        }
    }

    void DFS(int source)
    {
        static vector<bool> visited(V, false);
        queue<int> Q;

        visited[source] = true;
        cout << source << " ";

        for (auto element : adj[source])
        {
            int v = element.first;
            if (visited[v] != true)
            {
                DFS(v);
            }
        }
    }
};

class NonWGraph
{
    int V;
    list<int> *adj;

public:
    NonWGraph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }

    void printNeighbour(int chk)
    {
        cout << chk << ": ";
        for (auto i = adj[chk].begin(); i != adj[chk].end(); i++)
        {
            cout << *i
                 << " , ";
        }
    }
};

int main()
{
    // Weighted Graph
    int V, E, source;
    cin >> V >> E >> source;
    Graph g(V);
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    for (int i = 0; i < V; i++)
    {
        g.printNeighbour(i);
        cout << endl;
    }

    cout << endl
         << endl;

    g.BFS(source);
    cout << endl;
    g.DFS(source);
    cout << endl;
    // Non Weighted Graph
    // int V, E;

    // cin >> V >> E;
    // NonWGraph g(V);
    // for (int i = 0; i < E; i++)
    // {
    //     int u, v;
    //     cin >> u >> v;
    //     g.addEdge(u, v);
    // }

    // for (int i = 0; i < V; i++)
    // {
    //     g.printNeighbour(i);
    //     cout << endl;
    // }
    return 0;
}

/*
7 10 0
0 1 7
0 2 1
0 5 3
1 3 11
2 3 3
3 6 1
6 5 2
6 4 4
5 4 4
2 5 8
*/
