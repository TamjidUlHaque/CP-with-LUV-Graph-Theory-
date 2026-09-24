#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> visited;
vector<int> subTreeSum;
vector<int> evenCount;

void dfs(int node) {
    visited[node] = 1;

    int sumHere = node;                // start with node index as value
    int evenHere = (node % 2 == 0);    // count if node index is even

    for (auto child : graph[node]) {
        if (visited[child]) continue;
        dfs(child);

        // collect contributions from children
        sumHere += subTreeSum[child];
        evenHere += evenCount[child];
    }

    // assign once, outside the loop
    subTreeSum[node] = sumHere;
    evenCount[node] = evenHere;
}

int main() {
    int n , edge ; cin >> n >> edge;
    graph.assign(n+1 , vector<int>()) ; visited.assign(n+1 , 0) ;
    subTreeSum.assign(n+1 , 0) ; evenCount.assign(n+1 , 0);

    for (int i = 0; i < edge; i++) {
        int u, v ; cin >> u >> v ; u , v ;
        graph[u].push_back(v) ;
        graph[v].push_back(u) ;
    }

    dfs(1) ; int query ; cin >> query;
    while (query-->0) {
        int vertex ; cin >> vertex ;
        cout << subTreeSum[vertex] << ' ' ;
        cout << evenCount[vertex] << '\n';
    }

}
