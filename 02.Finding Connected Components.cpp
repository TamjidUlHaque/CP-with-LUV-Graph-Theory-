#include<bits/stdc++.h>
using namespace std ;

vector<vector<int>> graph ;
vector<int> visited ;

void dfs(int node , vector<int> &vec){
    visited[node] = 1 ; vec.push_back(node) ;
    for(auto child : graph[node]){
        if(visited[child]) continue ;
        dfs(child,vec) ;
    }
}

int main(){
    int n , edge ; cin >> n >> edge ;
    graph.assign(n,vector<int>()) ;
    visited.assign(n,0) ;
    vector<vector<int>> connected_components ;
    for(int i = 1 ; i <= edge ; i++){
        int u , v ; cin >> u >> v ; --u , --v ;
        graph[u].push_back(v) ; graph[v].push_back(u) ;
    }

    for(int i = 0 ; i < n ; i++){
        if(visited[i]) continue ;
        vector<int> components ; dfs(i,components) ;
        connected_components.push_back(components) ;
    }
    for(auto cc:connected_components){
        for(auto val:cc) cout << val+1 << ' ' ;
            cout << endl ;
    }
}
