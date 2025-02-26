
// g++ -o Graph Graph.cpp
// ./Graph

#include <bits/stdc++.h>
using namespace std;

class Graph {
    private:
        int V;
        vector<vector<int>> adj;

    public:
        Graph(int V)
        {
            this->V = V;
            adj.resize(V, vector<int>(0));
        }
        void displayGraph() {
            for(int i=0; i<V; i++) {
                cout << "Vertex " << i << ": ";
                for(auto neighbour : adj[i]) {
                    cout << neighbour << " ";
                }
                cout << endl;
            }
        }
        void addEdge(int u, int v) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);
    g.addEdge(2, 3);
    g.displayGraph();
    return 0;
}