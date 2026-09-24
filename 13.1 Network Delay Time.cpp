class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n+1,vector<pair<int,int>>()) ;
        vector<int> time_delay_to_reach(n+1,INT_MAX) ;
        vector<int> visited(n+1,0) ;

        for(auto vec:times){
            graph[vec[0]].push_back({vec[2],vec[1]}) ;
        }

priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> dijkstra ;
        time_delay_to_reach[k] = 0 ; dijkstra.push({0,k}) ;

        while(!dijkstra.empty()){

            pair<int,int> current = dijkstra.top() ; dijkstra.pop() ;

            int node = current.second ;

            if(visited[node]) continue ;

            visited[node] = 1 ;

            for(auto adj:graph[node]){

                int required_time =  adj.first  ;
                int new_node      =  adj.second ;

            if(time_delay_to_reach[node] + required_time < time_delay_to_reach[new_node]){
                time_delay_to_reach[new_node] = time_delay_to_reach[node] + required_time ;
                dijkstra.push(make_pair(time_delay_to_reach[new_node],new_node)) ;
            }

        }


    }

        int minTime = 0 ;

        for(int node = 1 ; node <= n ; node++){
            minTime = max(minTime,time_delay_to_reach[node]) ;
        }

        if(minTime == INT_MAX) minTime = -1 ;

        return minTime ;



    }
};
