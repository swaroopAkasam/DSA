/*
547. Number of Provinces
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfsTraversal(int node, vector<int>& visited, vector<vector<int>>& adj) {
        visited[node] = 1;
        for (int i = 0; i < adj.size(); i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                dfsTraversal(i, visited, adj);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& adj) {
        int ans = 0;
        int V = adj.size();
        vector<int> visited(V, 0); 
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                ans++;
                dfsTraversal(i, visited, adj);
            }
        }   
        return ans;
    }
};

int main() {
    int V = 3;
    vector<vector<int>> adj = {
        {1,1,0},
        {1,1,0},
        {0,0,1},
    };
    Solution sol;
    int ans = sol.findCircleNum(adj);
    cout << ans << endl;
    return 0;
}