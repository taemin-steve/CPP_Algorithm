#include <iostream>
#include <queue>


using namespace std;

int N, M;
pair<int, int> p;
queue<pair<int,int>> q;
string s;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};


int main(){
    cin >> N >> M;
    int m[N][M];  // 일단 이렇게 하고 뭐가 다른지 한번 확인해보자
    
    for( int i=0; i<N; i++){
        cin >> s;
        for(int j=0; j<M; j++){
            m[i][j] = s[j] - '0';
        }
    }

    q.push(make_pair(0,0)); // make_pair()는 특이한 함수! 이렇게 써서 바로 진행가능
    m[0][0] = 1;

    while(q.size()){
        p = q.front(); 
        q.pop();
        
        for(int i=0; i<4; i++){
            int ny = p.first + dy[i];
            int nx = p.second + dx[i];

            if(ny < 0 || ny >= N || nx < 0|| nx >=M) continue;
            if(m[ny][nx] == 0 || m[ny][nx] != 1) continue;
            m[ny][nx] = m[p.first][p.second] + 1;
            q.push(make_pair(ny,nx));
        }
    }

    cout << m[N-1][M-1] << endl;
}