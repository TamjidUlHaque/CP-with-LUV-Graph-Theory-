#include<bits/stdc++.h>
using namespace std ;

using ll = long long ;
const ll infinity = 1e17 ;

#define gap ' '
#define sesh '\n'
#define pii pair<ll,ll>

/*
    Topic Name :-
    ________________________________________Disjoint Set Union ( DSU )___________________________________________

    Disjoint Set Union muloto use hoy duita vinno connected component ke eksathe connect korte . DSU
    te muloto 3 ta function thake . Make function ja ekta notun node ke build kore .Search function kuno
    ekta node er parent node ke khuje ber kore . Erpore connect function oi duita vinno connected component er
    moddhe subidha onujai connection toiri kore .

    Er use kora hoy muloto eki boisister shokol jinish ke ekta group er awta vukto korar jonne . Make function
    ta ekta basic function jekhane shob node ke oi node er parent declare kore dewa hoy .

    Search Function jotokkhon na shompurno group er parent khuje na pay totokkhon khujte thakbe . Jokhon parent
    khuje pabe tokhon parent theke oi noder joto gula predecessor ache shobar parent oi parent ke kore dibe.
    Ei search Function er time complexity amortized time complexity ja almost O(1) e kaaj kore .

    Connect Function duita node er parent khuje ber kore . Jodi dekhe parent same tahole kuno operation kore na .
    Jodi duita node er parent same na hoy tobe jei parent er subtree size chuto oitar parent hisabe boro subtree
    size er parent ke set korbo . Boro Subtree size er sathe chuto subtree size add kore dibo .

    DSU er make function er time complexity O(1) . Search function er time complexity ke amortized time complexity
    bole . Eke greek letter alpha diye prokash kora hoy . T.C of Search() = O(alpha(n)) jekhane alpha er value eto
    slowly briddhi pay je n er value <= 1e18 er jonne alpha(n) er value <= 4 hoy .
    Alpha(n) ke inverse ackerman function o bola hoy . Connect function er khetre o time complexity O(alpha(n)) .

    Tarmane DSU is one of the most optimized data structure .
*/

vector<int> parent ;
vector<vector<int>> graph ;
vector<int> subtree_size ;

void make(int node){
    parent[node] = node ;
}

int search(int node){

    if(parent[node] == node) return node ;

    int root = search(parent[node]) ;

    parent[node] = root ;

    return parent[node] ;

}

void connect(int node1 , int node2){

    int par1 = search(node1) ;
    int par2 = search(node2) ;

    if(par1 != par2){
        if(subtree_size[par1] < subtree_size[par2]){
            swap(par1,par2) ;
        }

        subtree_size[par1] += subtree_size[par2] ;
        parent[par2] = par1 ;
    }


}


int main(){

    ios_base::sync_with_stdio(0) ; cin.tie(0) ;

    int n , query ; cin >> n >> query ;

    graph.assign(n+1,vector<int>()) ;
    parent.assign(n+1,-1) ; subtree_size.assign(n+1,1) ;

    for(int i = 1 ; i <= n ; i++) make(i) ;

    while(query--){

        int u , v ; cin >> u >> v ;

        connect(u,v) ;

    }

    int cc_cnt = 0 ;

    for(int node = 1 ; node <= n ; node++){
        if(parent[node] == node) cc_cnt++ ;
    }

    cout << cc_cnt << endl ;

    return 0 ;
}
