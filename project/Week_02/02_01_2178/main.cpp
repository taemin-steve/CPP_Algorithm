#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int N, M;
int adj[104][104]; // 한번에 여유있게 잡아주고
int visited[104][104];
int x,y;
queue<pair<int,int>> q;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int main(){
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%1d", &adj[i][j]); // 입출력에서, scanf랑 cin getline(cin, s) 이런것들 한번 모두 정리해 줘야 할거같음
        }
    }
    
    q.push({0,0}); // 우리에게는 1,1 >> 0,0
    visited[0][0] = 1;

    while(q.size()){
        tie(y,x) = q.front();q.pop();
        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if( ny<0 || ny>=N || nx<0 || nx>=M || adj[ny][nx] == 0) continue;
            if(visited[ny][nx]) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny,nx});
        }
    }

    printf("%d", visited[N-1][M-1]);
    return 0;
}