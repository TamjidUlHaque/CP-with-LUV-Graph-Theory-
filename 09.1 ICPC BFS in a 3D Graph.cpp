#include<bits/stdc++.h>
using namespace std ;
#define pii pair<int,int>
#define F first
#define S second

const int U = 55 ;

char reservoir[U][U][U] ;
int part_of_cc_no[U][U][U] ;

int X , Y , Z ;
int cnt = 0 ;

struct cell {
    int i , j , k ;
};

void bfs(int i , int j , int k , int &size){
    queue<cell> q ;
    q.push({i,j,k}) ;
    part_of_cc_no[i][j][k] = cnt ;

    int dx[6] = {1,-1,0,0,0,0} ;
    int dy[6] = {0,0,1,-1,0,0} ;
    int dz[6] = {0,0,0,0,1,-1} ;

    while(!q.empty()){
        cell cur = q.front() ; q.pop() ;
        size++ ;

        for(int d = 0 ; d < 6 ; d++){
            int nx = cur.i + dx[d] ;
            int ny = cur.j + dy[d] ;
            int nz = cur.k + dz[d] ;

            if(nx < 0 || ny < 0 || nz < 0 || nx >= X || ny >= Y || nz >= Z) continue ;
            if(reservoir[nx][ny][nz] == '#' || part_of_cc_no[nx][ny][nz] != 0) continue ;

            part_of_cc_no[nx][ny][nz] = cnt ;
            q.push({nx,ny,nz}) ;
        }
    }
}

void gas_reservoir(){
    cin >> X >> Y >> Z ; cnt = 0 ;

    memset(reservoir,'#',sizeof(reservoir)) ;
    memset(part_of_cc_no,0,sizeof(part_of_cc_no)) ;

    // input format: Z layers, each layer has X lines of length Y
    for(int k = 0 ; k < Z ; k++){
        for(int i = 0 ; i < X ; i++){
            string row ; cin >> row ;
            for(int j = 0 ; j < Y ; j++){
                reservoir[i][j][k] = row[j] ;
            }
        }
    }

    // find reservoirs
    vector<int> reservoir_size ;
    reservoir_size.push_back(0) ; // index 0 unused

    for(int i = 0 ; i < X ; i++){
        for(int j = 0 ; j < Y ; j++){
            for(int k = 0 ; k < Z ; k++){
                if(reservoir[i][j][k] == '#' || part_of_cc_no[i][j][k] != 0) continue ;
                cnt++ ;
                int size = 0 ;
                bfs(i,j,k,size) ;
                reservoir_size.push_back(size) ;
            }
        }
    }

    // compute max gas collected by drilling one borehole
    int answer = 0 ;
    for(int i = 0 ; i < X ; i++){
        for(int j = 0 ; j < Y ; j++){
            set<int> seen ;
            int total = 0 ;
            for(int k = 0 ; k < Z ; k++){
                int id = part_of_cc_no[i][j][k] ;
                if(id == 0) continue ;
                if(seen.count(id)) continue ;
                seen.insert(id) ;
                total += reservoir_size[id] ;
            }
            answer = max(answer,total) ;
        }
    }

    cout << answer << endl ;
}

int main(){
    ios_base::sync_with_stdio(0) ; cin.tie(0) ;

    int T ; cin >> T ;
    for(int t = 1 ; t <= T ; t++){
        gas_reservoir() ;
    }
    return 0 ;
}
