// 바구니를 옮길거야 // 스크린은 N 칸/ 아래 바구니 M 칸 
// 왼쪽 pos만 기억하고서 진행해주면 될거같은데?? 

#include <bits/stdc++.h>
using namespace std;

int N, M, J, l_pos, r_pos, apple, ret;

int main(){
    cin >> N >> M >> J;
    l_pos = 1;
    r_pos = M;
    for(int i=0; i<J; i++){
        cin >> apple;
        if( l_pos <= apple && apple <= r_pos) continue;
        else if (l_pos > apple){
            while(l_pos != apple){
                l_pos--;
                r_pos--;
                ret++;
            }
        }
        else if (r_pos < apple){
            while(r_pos != apple){
                l_pos++;
                r_pos++;
                ret++;
            }
        }
    }
    cout << ret;
}