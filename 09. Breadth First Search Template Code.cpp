#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;
#define sesh '\n'
#define gap ' '
#define pb push_back

vector<vector<int>> graph ;
vector<int> visited ;
vector<int> level ;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n , e ; cin >> n >> e ;
    graph.assign(n+1,vector<int>()) ;
    visited.assign(n+1,0) ; level.assign(n+1,0) ;

    for(int i = 0 ; i < e ; i++){
        int u , v ; cin >> u >> v ;
        graph[u].pb(v) ; graph[v].pb(u) ;
    }

    queue<int> bfs ; bfs.push(1) ;
// Jehetu bfs e node gula level wise traverse hoy tai un-weighted or equal-weighted graph
// e bfs amader shortest path khuje pete sahajjo kore .
    visited[1] = 1 ;

    while(!bfs.empty()){
        int node = bfs.front() ; bfs.pop() ;
        for(auto child:graph[node]){
            if(!visited[child]){
                level[child] = level[node] + 1 ;
                visited[child] = 1 ;
                bfs.push(child) ;
            }
        }
    }

    return 0;
}
