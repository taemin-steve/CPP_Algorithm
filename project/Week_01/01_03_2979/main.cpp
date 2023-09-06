#include <iostream>

using namespace std;

int fee[3];
int in, out;
int t[101];
int ans;

int main(){
    for(int i =0; i < 3; i++){
        cin >> fee[i];    
    }
    
    // 배열에 추가
    for(int i =0; i< 3; i++){
        cin >> in >> out;// 이렇게 동시에 받는거 가능 
        for(int j = in; j < out; j++){
            t[j] += 1;
        }
    }

    // 값 계산
    for(int i : t){
        if(i){// 0이면 거짓 
            ans += i * fee[i - 1]; // 해당 시간에 있는 차의 수 * 해당 요금  
        }
    }

    cout << ans;
}// 시간은 이상, 미만으로 잡아야 한다