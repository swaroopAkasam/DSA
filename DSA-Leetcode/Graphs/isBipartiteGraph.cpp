/*
785. Is Graph Bipartite?
There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:

There are no self-edges (graph[u] does not contain u).
There are no parallel edges (graph[u] does not contain duplicate values).
If v is in graph[u], then u is in graph[v] (the graph is undirected).
The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkBip(int i, vector<vector<int>>& graph, vector<int>& color) {
        color[i] = 0;
        queue<int> q;
        q.push(i);
        while(!q.empty()) {
            int node = q.front();
            int node_color = color[node];
            q.pop();
            for(const int neigh: graph[node]) {
                int neigh_color = color[neigh];
                if(neigh_color==-1) {
                    color[neigh] = !node_color;
                    q.push(neigh);
                }   
                else if(node_color==neigh_color) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i=0; i<n; i++) {
            if(color[i]==-1 && !checkBip(i, graph, color)) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;

    // ✅ Testcase 1: Bipartite graph (a square: 0-1-2-3-0)
    vector<vector<int>> graph1 = {
        {1, 3}, // node 0 connected to 1 and 3
        {0, 2}, // node 1 connected to 0 and 2
        {1, 3}, // node 2 connected to 1 and 3
        {0, 2}  // node 3 connected to 0 and 2
    };
    cout << "Testcase 1: " << sol.isBipartite(graph1) << " (Expected: 1)" << endl;

    // ❌ Testcase 2: Not bipartite (a triangle: 0-1-2-0)
    vector<vector<int>> graph2 = {
        {1, 2}, // node 0 connected to 1 and 2
        {0, 2}, // node 1 connected to 0 and 2
        {0, 1}  // node 2 connected to 0 and 1
    };
    cout << "Testcase 2: " << sol.isBipartite(graph2) << " (Expected: 0)" << endl;

    // ✅ Testcase 3: Disconnected bipartite graph
    vector<vector<int>> graph3 = {
        {1},    // 0-1
        {0},    
        {3},    // 2-3
        {2}
    };
    cout << "Testcase 3: " << sol.isBipartite(graph3) << " (Expected: 1)" << endl;

    // ✅ Testcase 4: Single node
    vector<vector<int>> graph4 = {
        {} // isolated node
    };
    cout << "Testcase 4: " << sol.isBipartite(graph4) << " (Expected: 1)" << endl;

    // ❌ Testcase 5: Odd cycle (5 nodes in cycle)
    vector<vector<int>> graph5 = {
        {1, 4}, // 0 connected to 1 and 4
        {0, 2},
        {1, 3},
        {2, 4},
        {0, 3}
    };
    cout << "Testcase 5: " << sol.isBipartite(graph5) << " (Expected: 0)" << endl;

    return 0;
}
