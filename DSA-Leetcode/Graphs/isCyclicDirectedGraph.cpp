
/*
Directed Graph Cycle
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge from verticex u to v.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
  void prepAdj(vector<vector<int>>& edges, vector<vector<int>>& adj) {
      for (auto const &edge : edges) {
          adj[edge[0]].push_back(edge[1]); // directed edge u -> v
      }
  }

  public:
    bool dfs(int i, vector<vector<int>> &adj, vector<int>& vis, vector<int>& path_vis) {
        vis[i] = 1;
        path_vis[i] = 1;

        for (const int neigh : adj[i]) {
            if (!vis[neigh]) {
                if (dfs(neigh, adj, vis, path_vis)) return true;
            } 
            else if (path_vis[neigh]) {
                return true; // back-edge found → cycle
            }
        }

        path_vis[i] = 0; // 🔑 cleanup when backtracking
        return false;
    }

    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        prepAdj(edges, adj);

        vector<int> vis(V, 0);
        vector<int> path_vis(V, 0);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, path_vis)) return true;
            }
        }
        return false;
    }
};


int main() {
    Solution sol;

    // Test 1: Graph with cycle: 0 -> 1 -> 2 -> 0
    vector<vector<int>> edges1 = {{0,1},{1,2},{2,0}};
    cout << "Test 1: " << sol.isCyclic(3, edges1) << " (Expected: 1)" << endl;

    // Test 2: Graph without cycle: 0 -> 1 -> 2
    vector<vector<int>> edges2 = {{0,1},{1,2}};
    cout << "Test 2: " << sol.isCyclic(3, edges2) << " (Expected: 0)" << endl;

    // Test 3: Disconnected graph with a cycle in one component
    vector<vector<int>> edges3 = {{0,1},{1,2},{2,0},{3,4}};
    cout << "Test 3: " << sol.isCyclic(5, edges3) << " (Expected: 1)" << endl;

    // Test 4: Single node self-loop
    vector<vector<int>> edges4 = {{0,0}};
    cout << "Test 4: " << sol.isCyclic(1, edges4) << " (Expected: 1)" << endl;

    // Test 5: Multiple disconnected acyclic components
    vector<vector<int>> edges5 = {{0,1},{2,3},{3,4}};
    cout << "Test 5: " << sol.isCyclic(5, edges5) << " (Expected: 0)" << endl;

    return 0;
}
