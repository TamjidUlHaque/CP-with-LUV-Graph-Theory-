#include<bits/stdc++.h>
using namespace std ;


/*
    Intuition :-

    ____________________{ 0-1 Breadth First Search Template Code }_____________________________

    Unweighted Graph e BFS amader ke shortest path khuje ber korte sahajjo kore . Kintu jodi graph
    weighted hoye jay tahole Dijkstra er algorithm er proyojon hoy shortest path khuje ber korar jonne.

    Dijkstra er Time Complexity O(n*(log(n))) . Jodi graph er weight kebol 0 and 1 hoy tahole 0-1 BFS
    amader ke shortest path khuje pete sahajjo kore O(n) time complexity teh .

    BFS er je queue ta ache er moddhe eksathe kebol matro duita level er element exist korte pare .
    Karon level x er element shob gula traversal sesh hole x+1 level er shobgula insertion sesh hoy .
    Thik jei muhurte x level er last element ta traverse sesh hoy and x+1 er shobcheye sesh element ta
    insert sesh hoy tokhon e x level er last node ta ber hoye jay . x+1 level er first element er adjacent
    node gula ke traversing shuru hoy .

    Amader ekhane mul idea holo amra queue er bodole ekta deque use korbo . Deque er moddhe current node
    er adjacent node gula edge weight jodi 0 hoy tahole oi duita node same level e ache eijonne deque te
    front e element ta push korbo . Ar jodi weight 1 hoy tahole next level er element tai push back korbo .

    _____________________________CODECHEF QUESTION :- Chef & Reversing_____________________________________

    Ekta graph dewa ache jar node songkha n and edge songkha m . Chef ke minimum koto gula edge ke reverse
    korte hobe 1st node theke n-th node e pouchanur jonne.

    Ekhane amra jei node gula given ache oigular weight 0 hishabe count korbo and eder biporit gula ke 1 hishabe
    count korbo . Tahole jodi 0 weight er ta diye jawa jay oita diye jabo . Nahole 1 weight er ta use korte
    hobe . Ar weight ta answer er sathe add hobe .

    0-1 BFS er moddhe amader ke visited array ta use korte hoy na if condition tar jonne . Ei condition ta ekta
    jinish nischit kore jeno kuno ekta node er child node duibar er beshi visit na hoy . Ekbar 1 weight er jonne
    INFINITY value ta shorate arekbar 0 use hoy 1 er value ta decrease korte .

*/

#define pii pair<int,int>

int main(){
    ios_base::sync_with_stdio(0) ; cin.tie(0) ;

    int n , m ; cin >> n >> m ;

    vector<vector<pii>> adj(n+1,vector<pii>()) ;

    for(int i = 1 ; i <= m ; i++){
        int u , v ; cin >> u >> v ;
        if(u==v) continue ;
        adj[u].push_back({v,0}) ;
        adj[v].push_back({u,1}) ;
    }


    vector<int> minReverse (n+1,INT_MAX) ;

    deque<int> bfs ; bfs.push_back(1) ;
    minReverse[1] = 0 ;

    while(!bfs.empty()){
        int node = bfs.front() ; bfs.pop_front() ;

        for(auto curr:adj[node]){
            int vertex = curr.first ;
            int weight = curr.second ;

            if(minReverse[node] + weight < minReverse[vertex]){
                minReverse[vertex] = minReverse[node] + weight ;
                if(weight==1){
                    bfs.push_back(vertex) ;
                }else{
                    bfs.push_front(vertex) ;
                }
            }
        }

    }

    if(minReverse[n]==INT_MAX) cout << "Impossible" << endl ;
    else cout << minReverse[n] << endl ;

    return 0 ;
}
