#include<bits/stdc++.h>
using namespace std ;

#define ll long long
#define pii pair<ll,ll>
#define vi vector<ll>

vi parent ;
vi subtree_size ;

void make(int node){
    parent[node] = node ;
    subtree_size[node] = 1 ;
}

int search_parent(int node){
    if(parent[node] == node) return node ;

    int root = search_parent(parent[node]) ;

    parent[node] = root ;

    return root ;
}

void connect(int source , int destination){
    int parent1 = search_parent(source) ;
    int parent2 = search_parent(destination) ;
    if(parent1 != parent2){
        if(subtree_size[parent1] < subtree_size[parent2])
            swap(parent1,parent2) ;
        parent[parent2] = parent1 ;
        subtree_size[parent1] += subtree_size[parent2] ;
    }
}

int main(){

    ios_base::sync_with_stdio(0) ; cin.tie(0) ;

    int n , e ; cin >> n >> e ;
    parent.assign(n+1,-1) ;
    subtree_size.assign(n+1,0) ;
    priority_queue<vi,vector<vi>,greater<vi>> krushkal ;

    for(int i = 1 ; i <= e ; i++){
        ll u , v , w ; cin >> u >> v >> w ;
        krushkal.push({w,u,v}) ;
    }

    for(int node = 1 ; node <= n ; node++) make(node) ;

    ll minimum_cost = 0 ;

    vector<vi> minimum_spanning_tree ;

    while(!krushkal.empty()){

        vi current = krushkal.top() ; krushkal.pop() ;
        ll cost = current[0] ;
        ll source = current[1] ;
        ll destination = current[2] ;

        if(search_parent(source)==search_parent(destination)) continue ;

        minimum_spanning_tree.push_back(current) ;

        minimum_cost += cost ;

        connect(source,destination) ;

    }

    int cc_cnt = 0 ;

    for(int node = 1 ; node <= n ; node++){
        if(parent[node] == node) cc_cnt++ ;
    }

    if(cc_cnt==1){
        cout << minimum_cost << '\n' ;
    }else{
        cout << "IMPOSSIBLE" << '\n' ;
    }

    return 0 ;
}
