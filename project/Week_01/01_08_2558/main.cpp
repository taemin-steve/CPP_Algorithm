#include <iostream>

using namespace std;

int N;
int K;
int acc[100010];
int sum;
int ans = -10000;

int main(){
    //배열 입력 받아서, 누적합 배열을 만들어주자. 
    cin >> N >> K;
    for(int i = 0; i < N; i++){ 
        int a;
        cin >> a;
        sum += a;
        acc[i+1] = sum; // 1부터 넣어줌. >> 이렇게 하면 3 ~ 1 까지의 누적합을 3-1로 가능 
    }
    
    for(int i = 0; i < N - K + 1; i++ ){ 
        if(acc[i+ K] - acc[i] > ans) ans = acc[i+K] - acc[i];
    }

    cout << ans;
}