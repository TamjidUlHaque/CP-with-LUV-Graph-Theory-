#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;
#define sesh '\n'
#define gap ' '
#define pb push_back

vector<vector<int>> graph ;
vector<int> visited ;
vector<int> value ;
vector<int> subtree_sum ;

void dfs(int node){
    visited[node] = 1 ;
    subtree_sum[node] = value[node] ;
    for(auto child:graph[node]){
        if(visited[child]) continue ;
        dfs(child) ;
        subtree_sum[node] += subtree_sum[child] ;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n , e ; cin >> n >> e ;
    graph.assign(n+1,{}) ; visited.assign(n+1,0) ;
    subtree_sum.assign(n+1,0) ; value.assign(n+1,0) ;

    for(int i = 0 ; i < e ; i++){
        int u , v ; cin >> u >> v ;
        graph[u].pb(v) ; graph[v].pb(u) ;
    }

    for(int i = 1 ; i <= n ; i++) cin >> value[i] ;

    dfs(1) ; int max_product = 1 ;

    for(int i = 2 ; i <= n ; i++){
        int curProduct = ((subtree_sum[i] % mod) * ((subtree_sum[1]-subtree_sum[i]+mod)%mod)) % mod ;
        max_product = max(max_product,curProduct) ;
    }

    cout << max_product << sesh ;

    return 0;
}
