// Link :- https://codeforces.com/contest/638/problem/B

// # Template Code for Depth First Search ( DFS ) .

#include <bits/stdc++.h>
using namespace std;

#define len(x) (int)((x).size())

const int N = 27 ;
vector<vector<int>> graph ;
vector<int> visited ;
string ans ;

void dfs(int vertex){
    ans.push_back((char)(vertex+'a')) ;
    visited[vertex] = 0 ;
    for(auto child:graph[vertex]){
        if(visited[child]==1) dfs(child) ;
    }
}

int main() {
    int n ; cin >> n ; vector<string> vec(n) ;
    for(int i = 0 ; i < n ; i++) cin >> vec[i] ;

    graph.assign(N,vector<int>()) ; visited.assign(N,-1) ;

    for(auto str:vec){
        for(int i = 0 ; i < len(str)-1 ; i++){
            graph[str[i]-'a'].push_back(str[i+1]-'a') ;
            visited[str[i+1]-'a'] = 1 ;
        }
    }

    for(auto str:vec){
        if(visited[str[0]-'a']==-1) visited[str[0]-'a'] = 2 ;
    }

    for(int i = 0 ; i < 26 ; i++){
        if(visited[i]==2) dfs(i) ;
    }

    cout << ans << endl ;

}
