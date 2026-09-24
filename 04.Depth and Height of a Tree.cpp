// Tree traversal via Depth First Search and calculating
// depth , height and subTreeSize of a Tree .

#include<bits/stdc++.h>
using namespace std ;

vector<vector<int>> graph ;
vector<int> visited ;
vector<int> height ;
vector<int> depth ;
vector<int> subTreeSize ;

void dfs(int node){
    visited[node] = 1 ; subTreeSize[node] = 1 ;
    for(auto child:graph[node]){
        if(visited[child]) continue ;
        depth[child] = depth[node]+1 ;
        subTreeSize[node] += subTreeSize[child] + 1 ;
        dfs(child) ;
        height[node] = max(height[node],1+height[child]) ;
    }
}

int main(){
    int n , edge ; cin >> n >> edge ;
    graph.assign(n,vector<int>()) ;
    visited.assign(n,0) ; height.assign(n,0) ;
    depth.assign(n,0) ; subTreeSize.assign(n,0) ;
    for(int i = 1 ; i <= edge ; i++){
        int u , v ; cin >> u >> v ; --u , --v ;
        graph[u].push_back(v) ; graph[v].push_back(u) ;
    }
    dfs(0) ;
    for(auto h:height) cout << h << ' ' ; cout << endl ;
    for(auto d:depth) cout << d << ' ' ; cout << endl ;
    for(auto sz:subTreeSize) cout << sz << ' ' ; cout << endl ;
}
