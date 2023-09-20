// K개의 직사각형을 그리는데, 나머지가 분리된 영역으로 나누어진다 
// M >> 세로 N>> 가로 
// input이 왼쪽 아래 >> 오른쪽 위로 줌. // 아래가 0,0 // 하던대로 하자. 안뒤집힘!
// 어쨋듯 floodfill 이고 DFS 쓸거임! // 개수, 영역의 크기를 알려줘야 함!

#include <bits/stdc++.h>
using namespace std;
const int max_size = 101;
int adj[max_size][max_size], M, N, K, roi[4], visited[max_size][max_size], f_n, ret;
vector<int> v;

int dy[] = {1,0,-1,0};
int dx[] = {0,1,0,-1};

void DFS(int y , int x){
    f_n++; // 방문할때 마다 count 해줌!
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if( ny<0 || ny>= M || nx<0 || nx>=N) continue;
        if( visited[ny][nx] || adj[ny][nx] == 1) continue;
        visited[ny][nx] = 1;
        DFS(ny,nx);
    }
}

int main(){
    cin >> M >> N >> K; 
    for(int i=0; i<K; i++){
        cin >> roi[0] >> roi[1] >> roi[2] >> roi[3];
        for(int j=roi[1]; j< roi[3]; j++){ //int j=roi[1]; j< (roi[3] - roi[1]+ 1 까지임 .. 반복횟수를 적어주는게 아니야.. python이랑 헷깔리지 말자... 
            for(int k = roi[0]; k < roi[2]; k++){
                adj[j][k] = 1;
            }
        }
    }

    for(int i=0; i<M ; i++){
        for(int j=0; j<N; j++){
            if(visited[i][j] || adj[i][j] == 1) continue;
            f_n = 0;
            visited[i][j] = 1;
            DFS(i,j);
            ret ++;
            v.push_back(f_n);
        }
    }
    cout << ret << endl;
    sort(v.begin(), v.end());
    for(int i : v) cout << i << " ";
}
