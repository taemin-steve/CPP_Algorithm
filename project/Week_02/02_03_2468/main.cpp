#include <bits/stdc++.h>
using namespace std;
const int max_num = 104;
int N, adj[max_num][max_num], visited[max_num][max_num], safe_zone[max_num], max_height;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

void DFS(int y, int x, int h){
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if( ny<0 || ny>=N || nx<0 || nx>=N || adj[ny][nx] <= h) continue;
        if(visited[ny][nx]) continue;
        visited[ny][nx] = 1;
        DFS(ny,nx,h);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> adj[i][j];
        }
    }
    int max_element = 0;
    for(int h=0 ; h<101; h++){ // 최솟값 예외 처리 못했음....
        int ret = 0;
        fill(&visited[0][0], &visited[0][0] + max_num * max_num, 0);
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(visited[i][j] || adj[i][j] <= h) continue;
                ret ++;
                DFS(i,j,h);
            }
        }
        max_element = max(max_element, ret);
    }
    cout << max_element;
}