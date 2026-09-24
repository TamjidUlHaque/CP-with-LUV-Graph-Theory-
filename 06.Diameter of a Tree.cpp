#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> depth;

void dfs(int node , int parent){
    for(auto child : graph[node]){
        if(child==parent) continue ;
        depth[child] = depth[node] + 1 ;
        dfs(child,node) ;
    }
}

int main() {
    int n , edge ; cin >> n >> edge;
    graph.assign(n+1 , vector<int>()) ; depth.assign(n+1,0) ;

    for (int i = 0; i < edge; i++) {
        int u, v ; cin >> u >> v ;
        graph[u].push_back(v) ;
        graph[v].push_back(u) ;
    }
    dfs(1,-1) ; int one_side = 1 ;
    int max_distance = -1 ;
    for(int i = 1 ; i <= n ; i++){
        if(depth[i]>max_distance){
            max_distance = depth[i] ; one_side = i ;
        }
        depth[i] = 0 ;
    }
    dfs(one_side,-1) ;
    int another_side = 0 ;
    max_distance = -1 ;
    for(int i = 1 ; i <= n ; i++){
        if(depth[i]>max_distance){
            max_distance = depth[i] ; another_side = i ;
        }
        depth[i] = 0 ;
    }
    cout << max_distance << ' ' ;
    cout << one_side << ' ' << another_side << endl ;
}
