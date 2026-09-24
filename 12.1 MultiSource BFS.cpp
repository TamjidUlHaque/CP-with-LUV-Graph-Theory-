#include<bits/stdc++.h>
using namespace std ;

#define pii pair<int,int>

int dirX[4] = { -1 , 1 , 0 , 0 } ;
int dirY[4] = { 0 , 0 , -1 , 1 } ;
char Direction[4] = { 'U' , 'D' , 'L' , 'R' } ;

int main(){

    ios_base::sync_with_stdio(0) ; cin.tie(0) ;

    int row , column ; cin >> row >> column ;

    pii destination ;

    vector<vector<char>> grid(row+2,vector<char> (column+2,'#')) ;
    vector<vector<char>> path(row+2,vector<char> (column+2,'?')) ;

    vector<vector<int>> shortestPath(row+2,vector<int> (column+2,INT_MAX)) ;
    vector<vector<int>> monsters_path(row+2,vector<int> (column+2,INT_MAX)) ;

    queue<pii> bfs , monsters ;

    for(int i = 1 ; i <= row ; i++){
        for(int j = 1 ; j <= column ; j++){

            cin >> grid[i][j] ;

            if(grid[i][j] == 'M'){
                monsters.push({i,j}) ;
                monsters_path[i][j] = 0 ;
            }

            if(grid[i][j] == 'A'){
                shortestPath[i][j] = 0 ;
                bfs.push({i,j}) ;
                destination = {i,j} ;
            }

        }
    }

    while(!bfs.empty()){

        pii cell = bfs.front() ; bfs.pop() ;

        int x = cell.first , y = cell.second ;

        for(int idx = 0 ; idx < 4 ; idx++){
            int dx = x + dirX[idx] ;
            int dy = y + dirY[idx] ;

            if(dx < 1 or dy < 1 or dx > row or dy > column) continue ;
            if(grid[dx][dy] == '#') continue ;

            if(shortestPath[dx][dy] > (shortestPath[x][y]+1)){
                shortestPath[dx][dy] = shortestPath[x][y] + 1 ;
                path[dx][dy] = Direction[idx] ;
                bfs.push({dx,dy}) ;
            }

        }

    }

    while(!monsters.empty()){

        pii cell = monsters.front() ; monsters.pop() ;

        int x = cell.first , y = cell.second ;

        for(int idx = 0 ; idx < 4 ; idx++){
            int dx = x + dirX[idx] ;
            int dy = y + dirY[idx] ;

            if(dx < 1 or dy < 1 or dx > row or dy > column) continue ;

            if(grid[dx][dy] != '#' and monsters_path[dx][dy] > (monsters_path[x][y]+1)){
                monsters_path[dx][dy] = monsters_path[x][y] + 1 ;
                monsters.push({dx,dy}) ;
            }

        }

    }

    pii start ; bool impossible = true ;

    for(int i = 1 ; i <= row ; i++){
        if(!impossible) break ;
        for(int j = 1 ; j <= column ; j++){
            if((i==1 or j == 1 or i == row or j == column)){
                if(monsters_path[i][j] > shortestPath[i][j]){
                    start = {i,j} ;
                    impossible = false ;
                    break ;
                }
            }
        }
    }

    if(impossible) cout << "NO" << '\n' ;
    else{
        cout << "YES" << '\n' ;

        vector<char> moves ;

        while(true){

            if(start==destination) break ;
            int dx = start.first , dy = start.second ;
            moves.push_back(path[dx][dy]) ;


            if(path[dx][dy] == 'U') start.first++ ;
            if(path[dx][dy] == 'D') start.first-- ;
            if(path[dx][dy] == 'L') start.second++ ;
            if(path[dx][dy] == 'R') start.second-- ;

        }

        reverse(moves.begin(),moves.end()) ;

        cout << (int)(moves.size()) << '\n' ;

        for(auto curMove:moves) cout << curMove ;

        cout << '\n' ;

    }

    return 0 ;
}
