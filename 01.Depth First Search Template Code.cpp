// # Template Code for Depth First Search ( DFS ) .

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> visited;

void dfs(int node, int parent) {
    // Take action on node after entering the node .
    visited[node] = 1;
    for (auto child : graph[node]) {
        if (!visited[child]) {
    // Take action on child before entering the child node .
            dfs(child, node);
    // Take action on child after exiting the child node .
        }
    }
    // Take action on node before exiting the node .
}

int main() {
    int n, edge;
    cin >> n >> edge;

    graph.assign(n + 1, vector<int>());
    visited.assign(n + 1, 0);

    for (int i = 1; i <= edge; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1, -1) ;
}
