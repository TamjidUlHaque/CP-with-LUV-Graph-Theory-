#include<bits/stdc++.h>
using namespace std ;

using ll = long long ;
const ll infinity = 1e17 ;

/*
    Intuition :-                        Floyd Warshal Algorithm

    Multiple source theke multiple destination ber korar jonne floyd warshal algorithm use hoy .
    Ei algorithm er moddhe prothome shob node theke shob node er distance infinity diye initialize
    kora hoy . Er pore node gular nijeder theke nijeder distance ke 0 diye initialize kora hoy .

    Input newar shomoy mone mone dhora hoy je kebol u theke v tei amra jete parbo . Onno kuno node
    er sahajjo niye jete parbo na . Ei jinish ta dhore newar pore ekta shortest distance ber hoy for
    every u,v . Ekhon amra ekta ekta kore node ke allow kori je oi node er moddhe diye shortest_path
    jete pare . Tokhon previous value ar ekhon er value er moddhe compare kore best ta store kore
    rakhe . Ei algorithm ta muloto Dynamic Programming Based ekta approach jekhane ekta 2D table toiri
    er maddhome shortest distance er track rakha hocche . Floyd Warshal Algorithm er time complexity
    holo O(n^3) and space complexity holo O(n^2) .

    1) Positive and Negative both weight er jonne ei algorithm kaaj korbe .

    2) Jodi graph er moddhe kuno negative cycle thake tobe ei algorithm kaaj korbe na .
    Karon negative cycle diye jotobar asha jawa kora hobe totoi weight komte thakbe .
    Shortest_Path chuto hote thakle Shortest_Path calculate kora shomvob na .
    Ekhane negative cycle bolte shobgula weight er summation (-ve) bujhanu hocce .

*/

int main(){

    ios_base::sync_with_stdio(0) ; cin.tie(0) ;

    int nodes , edges , queries ; cin >> nodes >> edges >> queries ;

    vector<vector<ll>> minDistance(nodes+1, vector<ll> (nodes+1,infinity)) ;

    for(int i = 1 ; i <= nodes ; i++) minDistance[i][i] = 0 ;

    for(int edge = 1 ; edge <= edges ; edge++){
        ll u , v , w ; cin >> u >> v >> w ;
        minDistance[u][v] = min(minDistance[u][v],w) ;
        minDistance[v][u] = min(minDistance[v][u],w) ;
    }

    for(int allowed = 1 ; allowed <= nodes ; allowed++){
        for(int i = 1 ; i <= nodes ; i++){
            for(int j = 1 ; j <= nodes ; j++){
                if(minDistance[i][allowed] == infinity || minDistance[allowed][j] == infinity) continue ;

                ll new_path = minDistance[i][allowed] + minDistance[allowed][j] ;

                minDistance[i][j] = min(minDistance[i][j],new_path) ;
            }
        }
    }

    for(int query = 1 ; query <= queries ; query++){

        int source , destination ; cin >> source >> destination ;

        ll answer = minDistance[source][destination] ;

        cout << (answer == infinity ? -1 : answer) << '\n' ;

    }

    return 0 ;

}
