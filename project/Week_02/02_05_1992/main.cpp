// 재귀로 풀꺼고, return 해줄때 각각의 영역이 모두 같은거라면 그냥 return 아니면 ()싸서 리턴!
#include <bits/stdc++.h>
#pragma warning(disable:4996)
using namespace std;
const int max_size = 66;
int N, adj[max_size][max_size];

string DFS(int y , int x, int size){
    if(size == 1) return to_string(adj[y][x]);
    int n_size = size /2;
    string a1 = DFS(y, x, n_size); // Z자 형식으로 내려가야함
    string a2 = DFS(y, x + n_size, n_size);
    string a3 = DFS(y+ n_size, x, n_size);
    string a4 = DFS(y+ n_size, x+ n_size, n_size);
    if( a1 == a2 && a2 == a3 && a3 == a4){// DFS 네번 실행해주고, 값 같으면 
        if(a1 == "1" || a1 == "0"){
            return a1;
        }
        else return "(" + a1+a2+a3+a4 + ")";
    } 
    // if( a1 == a2 && a2 == a3 && a3 == a4){ // 이거는 알기 너무 힘든데..? 운이 좋아서 찾은거지.. 
    //     return a1;
    // } // DFS 네번 실행해주고, 값 같으면 
    else return "(" + a1+a2+a3+a4 + ")";
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%1d" , &adj[i][j]);
        }
    }
    string ret = DFS(0,0,N);
    printf("%s", ret.c_str());
    //시작지점을 어떻게 설정할 것인지가 좀 문제인데.. 기준점이랑, max size 를 줘서 해결하자. 
}