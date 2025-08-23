#include<bits/stdc++.h>
using namespace std;

class Graph {
public:
    vector<vector<int>> adj;
    int V;
    Graph(int v) {
        this->V = v;
        this->adj = vector<vector<int>>(V, vector<int>(0));
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void displayGraph() {
        for(int i=0; i<V; i++) {
            cout << "Vertex: " << i << " : ";
            for(auto ele: adj[i]) {
                cout << ele << " ";
            }
            cout << endl;
        }
    }
    vector<int> bfs(int source) {
        vector<int> ans;
        vector<int> visited(V+1, 0);
        queue<int> q;
        q.push(source);
        visited[source] = 1;
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            ans.push_back(front);
            for(auto ele: adj[front]) {
                if(!visited[ele]) {
                    visited[ele] = 1;
                    q.push(ele);
                }
            }
        }
        return ans;
    }    
};

class GraphAdjMat {
public:
    int V;
    vector<vector<int>> adjMat;
    GraphAdjMat(int v) {
        this->V = v;
        adjMat = vector<vector<int>> (V+1, vector<int>(V+1, 0));
    }
    void addEdge(int u, int v) {
        adjMat[u][v] = 1;
        adjMat[v][u] = 1;
    }
    void displayAdjMat() {
        for(int i=0; i<=V; i++) {
            for(int j=0; j<=V; j++) {
                cout << adjMat[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    cout << "Hello World" << endl;
    // vector<vector<int>> adj = {{0, 1}, {1, 2}, {2, 3}, {3, 0}, {2, 3}};
    Graph g(4);

    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.displayGraph();
    vector<int> ans = g.bfs(0);
    cout << "BFS Trav: ";
    for(auto ele: ans) cout << ele << " ";
    cout << endl;
}