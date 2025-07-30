// g++ -o Graph Graph.cpp
// ./Graph

#include <bits/stdc++.h>
using namespace std;

//  Adjacency List:
class Graph {
    private:
        int V;
        vector<vector<int>> adj;

    public:
        Graph(int V)
        {
            this->V = V;
            this->adj = vector<vector<int>>(V, vector<int>(0));
        }
        void addEdge(int u, int v) {
            adj[u].push_back(v);
            adj[v].push_back(u);
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
};

// Adjacency Matrix:
class GraphAdjMat {
private:
    int V;
    vector<vector<int>> mat;
public:
    GraphAdjMat(int V) {
        this->V = V;
        mat = vector<vector<int>>(V+1, vector<int>(V+1, 0));
    }
    void addEdge(int u, int v) {
        mat[u][v] = 1;
        mat[v][u] = 1;
    }
    void printMatrix() {
        for(int i=0; i<=V; i++) {
            for(int j=0; j<=V; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
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
    cout << endl;
    GraphAdjMat gm(3);
    gm.addEdge(1, 2);
    gm.addEdge(2, 3);
    gm.printMatrix();
    return 0;
}