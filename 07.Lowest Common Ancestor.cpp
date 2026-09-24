#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> father;

void dfs(int node , int parent){
    father[node] = parent ;
    for(auto child : graph[node]){
        if(child==parent) continue ;
        dfs(child,node) ;
    }
}

vector<int> path(int node){
    int x = node ; vector<int> temp ;
    while(x != -1){
        temp.push_back(x) ; x = father[x] ;
    }
    reverse(temp.begin(),temp.end()) ;
    return temp ;
}

int main() {
    int n , edge ; cin >> n >> edge;
    graph.assign(n+1 , vector<int>()) ; father.assign(n+1,0) ;

    for (int i = 0; i < edge; i++) {
        int u, v ; cin >> u >> v ;
        graph[u].push_back(v) ;
        graph[v].push_back(u) ;
    }

    dfs(1,-1) ;
    vector<int> path1 = path(7) ;
    vector<int> path2 = path(4) ;

    int lowest_common_ancestor = 1 ;
    for(int i = 0 ; i < min(int(path1.size()),int(path2.size()));i++){
        if(path1[i]==path2[i]){
            lowest_common_ancestor = path1[i] ;
        }else break ;
    }

    cout << lowest_common_ancestor << '\n' ;

}
