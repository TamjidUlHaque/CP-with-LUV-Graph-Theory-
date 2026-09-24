#include<bits/stdc++.h>
using namespace std ;

#define ll long long
#define pii pair<ll,ll>
#define infinity LLONG_MAX

int main(){

    ios_base::sync_with_stdio(0) ; cin.tie(0) ;

    int n , e ; cin >> n >> e ;

    vector<vector<pii>> graph(n+1,vector<pii> ()) ;

    for(int i = 1 ; i <= e ; i++){
        ll source , destination , len ;
        cin >> source >> destination >> len ;
        graph[source].push_back({len,destination}) ;
    }

    priority_queue< pii , vector<pii> , greater<pii> > dijkstra ;

    vector<ll> shortest_path_to_reach(n+1,infinity) ;
    vector<int> visited(n+1,0) ;

    dijkstra.push(make_pair(0,1)) ;
    shortest_path_to_reach[1] = 0 ;

    while(!dijkstra.empty()){

        pii current = dijkstra.top() ; dijkstra.pop() ;

        ll city = current.second ;

        if(visited[city]) continue ;

        visited[city] = 1 ;

        for(auto neighbour:graph[city]){

            ll distance = neighbour.first ;
            ll n_city = neighbour.second ;

            if(shortest_path_to_reach[city]+distance < shortest_path_to_reach[n_city]){
                shortest_path_to_reach[n_city] = shortest_path_to_reach[city]+distance ;
                dijkstra.push(make_pair(shortest_path_to_reach[n_city],n_city)) ;
            }

        }

    }

    for(int city = 1 ; city <= n ; city++){

        if(shortest_path_to_reach[city] == infinity){
            cout << -1 ;
        }else{
            cout << shortest_path_to_reach[city] ;
        }

        if(city==n) cout << '\n' ;
        else cout << ' ' ;

    }
}


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n+1,vector<pair<int,int>>()) ;
        vector<int> time_delay_to_reach(n+1,INT_MAX) ;
        vector<int> visited(n+1,0) ;

        for(auto vec:times){
            graph[vec[0]].push_back({vec[2],vec[1]}) ;
        }

        priority_queue< pair<int,int> , vector<pair<int,int>> , greater<int,int>> dijkstra ;
        time_delay_to_reach[k] = 0 ; dijkstra.push({0,k}) ;

        while(!dijkstra.empty()){

            pair<int,int> current = dijkstra.top() ; dijkstra.pop() ;

            int node = current.second ;

            if(visited[node]) continue ;

            visited[node] = 1 ;

            for(auto adj:graph[node]){

                ll required_time =  adj.first  ;
                ll new_node      =  adj.second ;

            if(time_delay_to_reach[node] + required_time < time_delay_to_reach[new_node]){
                time_delay_to_reach[new_node] = time_delay_to_reach[node] + required_time ;
                dijkstra.push(make_pair(time_delay_to_reach[new_node],new_node)) ;
            }

        }

        int minimum_time = 0 ;

        for(int node = 1 ; node <= n ; node++){
            minTime = max(minTime,time_delay_to_reach[node]) ;
        }

        if(minTime == INT_MAX) return -1 ;
        else return minTime ;
    }


    }
};
