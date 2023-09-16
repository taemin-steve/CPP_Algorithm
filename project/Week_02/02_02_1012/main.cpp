#include <bits/stdc++.h>
const int m = 54;
using namespace std;
int T,N,M,K,adj[54][54], visited[54][54], x, y, ret;

int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};

void DFS(int y, int x){
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny<0 || ny>=N || nx<0 || nx>=M || adj[ny][nx] == 0) continue;
        if(visited[ny][nx]) continue;
        visited[ny][nx] = ret;
        DFS(ny,nx);
    }
    
}

int main(){
    cin >> T;
    
    for(int t=0; t<T; t++){

        fill(&visited[0][0], &visited[0][0] + m*m , 0);
        fill(&adj[0][0], &adj[0][0] + m*m , 0);


        cin >> M >> N >> K; // 가로 세로로 들어왔음!
        for(int i=0; i<K; i++){ // 지도 입력받기 
            cin >> x >> y;
            adj[y][x] = 1;
        }

        ret = 0;
        
        for(int i=0; i< N; i++){
            for(int j=0; j<M; j++){
                if(visited[i][j] == 0 && adj[i][j] != 0){
                    ret ++;
                    DFS(i,j);
                }
            }
        }

        cout << ret << endl;
    }
}