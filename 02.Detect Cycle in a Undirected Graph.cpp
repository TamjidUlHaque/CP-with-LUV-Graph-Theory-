#include<bits/stdc++.h>
using namespace std ;

vector<vector<int>> graph ;
vector<int> visited ;

bool dfs(int node , int parent){
    visited[node] = 1 ;
    bool hasCycle = false ;
    for(auto child : graph[node]){
        if(visited[child] and child==parent) continue ;
        if(visited[child]) return true ;
        hasCycle |= dfs(child,node) ;
    }
    return hasCycle ;
}

int main(){
    int n , edge ; cin >> n >> edge ;
    graph.assign(n,vector<int>()) ;
    visited.assign(n,0) ;
    for(int i = 1 ; i <= edge ; i++){
        int u , v ; cin >> u >> v ; --u , --v ;
        graph[u].push_back(v) ; graph[v].push_back(u) ;
    }
    bool cyclic = false ;
    for(int i = 0 ; i < n ; i++){
        if(visited[i]) continue ;
        if(dfs(i,-1)){
            cyclic = true ; break ;
        }
    }
    if(cyclic) cout << "Cyclic Graph" << endl ;
    else cout << "No Cycles Detected" << endl ;
}
