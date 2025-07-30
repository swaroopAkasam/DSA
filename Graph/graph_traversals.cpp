#include<bits/stdc++.h>
using namespace std;

class GraphTrav {
private:
    vector<vector<int>> adj;
public:
    GraphTrav(vector<vector<int>>& adj) {
        this->adj = adj;
    }
    void displayAdjList() {
        for(int i=0; i<adj.size(); i++) {
            cout << i << " -> ";
            for(auto ele: adj[i]) {
                cout << ele << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    vector<int> bfsTraversal() {
        /*
        T.C: O(V) + O(2*E) ~ O(V+E) i.e O(V) the queue will run for V vertices, O(2*E) inside queue it will run 2*E time which is the degree of the graph.
        */
        vector<int> bfs;
        queue<int> q;
        vector<int> visited(adj.size(), 0);
        q.push(0);
        visited[0] = 1;
        while(!q.empty()) {
            int node = q.front();
            q.pop();    
            bfs.push_back(node);

            for(auto ele: adj[node]) {
                if(!visited[ele]) {
                    q.push(ele);
                    visited[ele] = 1;
                }
            }
        }
        return bfs;
    }
};

int main() {
    int V = 4; // Number of vertices
    vector<vector<int>> adj(V);  // 0-based indexing

    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 3};
    adj[3] = {1, 2};
    GraphTrav g(adj);
    g.displayAdjList();
    cout << endl;
    vector<int> bfs = g.bfsTraversal();
    for(auto ele: bfs) cout << ele << " ";
    cout << endl;
    return 0;
}