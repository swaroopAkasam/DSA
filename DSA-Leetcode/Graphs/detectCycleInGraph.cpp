#include<bits/stdc++.h>
using namespace std;

class BfsSolution {
  public:
    void prepAdjList(vector<vector<int>>& edges, vector<vector<int>>& adj) {
        for(auto &edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }   
    }
    bool detect(int src, vector<vector<int>>& adj, int V, vector<int>& visited) {
        if(visited[src]) return false;
        visited[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});
        while(!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto ele: adj[node]) {
                if(!visited[ele]) {
                    visited[ele] = 1;
                    q.push({ele, node});
                }
                else if(parent != ele) {
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        prepAdjList(edges, adj);
        vector<int> visited(V, 0);
        for(int i=0; i<V; i++) {
            if(!visited[i] && detect(i, adj, V, visited)) return true;
        }
        return false;
    }
};

class DfsSolution {
  public:
    void prepAdjList(vector<vector<int>>& edges, vector<vector<int>>& adj) {
        for(auto &edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }   
    }
    bool detect(int src, int parent, vector<vector<int>>& adj, vector<int>& visited) {
        visited[src] = 1;
        for(auto ele: adj[src]) {
            if(!visited[ele]) {
                if(detect(ele, src, adj, visited)) return true;
            }
            else {
                if(ele != parent) return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        prepAdjList(edges, adj);
        vector<int> visited(V, 0);
        for(int i=0; i<V; i++) {
            if(!visited[i] && detect(i, -1, adj, visited)) return true;
        }
        return false;
    }
};


int main() {
    BfsSolution bfsSol;
    DfsSolution dfsSol;
    // Test Case 1
    // vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 3}};
    // Test Case 2
    // vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}};
    // Test Case 3
    vector<vector<int>> edges = {{0, 1},{1, 2},{1, 3},{2, 4},{3, 4},{4, 5}};
    int V = 6;
    cout << bfsSol.isCycle(V, edges) << endl;
    cout << dfsSol.isCycle(V, edges) << endl;
}