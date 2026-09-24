#include<bits/stdc++.h>
using namespace std ;

using ll = long long ;
const ll infinity = 1e17 ;

#define gap ' '
#define sesh '\n'
#define pii pair<ll,ll>

/*

*/

int main(){

    ios_base::sync_with_stdio(0) ; cin.tie(0) ;

    int nodes ; cin >> nodes ;

    vector<vector<ll>> graph(nodes+1,vector<ll> (nodes+1,infinity)) ;

    for(int source = 1 ; source <= nodes ; source++){
        for(int destination = 1 ; destination <= nodes ; destination++){
            ll path_len ; cin >> path_len ;
            graph[source][destination] = min(graph[source][destination],path_len) ;
        }
    }

    vector<int> removing_sequence(nodes+1,0) ;
    vector<int> is_active(nodes+1,0) ;

    vector<ll> answer ;

    for(int i = nodes ; i >= 1 ; i--) cin >> removing_sequence[i] ;

    for(int idx = 1 ; idx <= nodes ; idx++){

        int k = removing_sequence[idx] ;

        ll shortest_path = 0 ; is_active[k] = 1 ;

        for(int i = 1 ; i <= nodes ; i++){
            for(int j = 1 ; j <= nodes ; j++){
                if(graph[i][k] == infinity) continue ;
                if(graph[k][j] == infinity) continue ;
                ll new_path = graph[i][k] + graph[k][j] ;
                graph[i][j] = min(graph[i][j],new_path) ;
            }
        }

        for(int i = 1 ; i <= nodes ; i++){
            if(!is_active[i]) continue ;
            for(int j = 1 ; j <= nodes ; j++){
                if(!is_active[j]) continue ;
                shortest_path += graph[i][j] ;
            }
        }

        answer.push_back(shortest_path) ;

    }

    reverse(answer.begin(),answer.end()) ;

    for(auto val:answer) cout << val << gap ;

    cout << sesh ;

    return 0 ;
}
