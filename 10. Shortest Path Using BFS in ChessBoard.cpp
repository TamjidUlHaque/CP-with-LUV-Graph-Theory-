#include<bits/stdc++.h>
using namespace std ;
#define pii pair<int,int>
#define F first
#define S second

int dirX[8] = {-2,-2,+2,+2,-1,-1,+1,+1} ;
int dirY[8] = {-1,+1,+1,-1,+2,-2,+2,-2} ;

int main(){

    ios_base::sync_with_stdio(0) ; cin.tie(0) ;

    int testcase ; cin >> testcase ;

    for(int test = 1 ; test <= testcase ; test++){

        string a , b ; cin >> a >> b ;

        pii start = {a[0]-'a',a[1]-'1'} ;
        pii destination = {b[0]-'a',b[1]-'1'} ;

        vector<vector<int>> minMoves(8,vector<int> (8,INT_MAX)) ;

        queue<pii> bfs ; bfs.push(start) ;

        minMoves[start.F][start.S] = 0 ;

        while(!bfs.empty()){
            pii square = bfs.front() ; bfs.pop() ;

            for(int i = 0 ; i < 8 ; i++){
                int x = square.F + dirX[i] ;
                int y = square.S + dirY[i] ;

                if(x >= 8 or y >= 8 or x < 0 or y < 0) continue ;

                if(minMoves[x][y] <= minMoves[square.F][square.S]) continue ;

                minMoves[x][y] = 1 + minMoves[square.F][square.S] ;
                bfs.push({x,y}) ;

            }
        }

        cout << minMoves[destination.F][destination.S] << endl ;

    }
}
