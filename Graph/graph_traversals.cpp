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
    vector<int> bfsTraversal(int start) {
        /*
        T.C: O(V) + O(2*E) ~ O(V+E) i.e O(V) the queue will run for V vertices, O(2*E) inside queue it will run 2*E time which is the degree of the graph.
        S.C: O(V)
            visited[] array → O(V)
            queue for BFS → at most O(V) in worst case
            bfs[] result array → O(V)
            Total auxiliary space = O(V)
        */
        vector<int> bfs;
        queue<int> q;
        vector<int> visited(adj.size(), 0);
        q.push(start);
        visited[start] = 1;
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

    void dfsTraversal(int node, vector<int>& visited, vector<int>& dfs) {
        /*
        T.C: O(V + E)
        S.C: O(V)
            visited[] array → O(V)
            Call stack (recursive DFS) worst-case O(V)
            So total auxiliary space = O(V)
        */
        visited[node] = 1;
        dfs.push_back(node);
        for(auto ele: adj[node]) {
            if(!visited[ele]) {
                dfsTraversal(ele, visited, dfs);
            }
        }
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

    // BFS Traversal
    vector<int> bfs = g.bfsTraversal(2);
    for(auto ele: bfs) cout << ele << " ";
    cout << endl;

    // DFS Traversal
    vector<int> dfs;
    vector<int> visited(V, 0);
    g.dfsTraversal(0, visited, dfs);
    for(auto ele: dfs) cout << ele << " ";
    cout << endl;

    return 0;
}