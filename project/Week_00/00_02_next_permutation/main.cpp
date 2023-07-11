#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> a = {1,2,3, 30,12,100}; //
    sort(a.begin(), a.end());
    do{
        // 범위 기반 for문 >> for(데이터 타입 elem : 데이터 리스트) 형식으로 알아서 반복하게끔 가능
        for(int i : a) cout << i << " ";
        cout << '\n';
    }while(next_permutation(a.begin(), a.end()));
    // next_permutation 시작 문자열과, 끝 문자열을 알려주면, 계속해서 다음 순열을 알려주고, 
    // 더이상 return 할 것이 없는경우 False를 return
}