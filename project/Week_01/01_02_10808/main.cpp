// #include <iostream>
// #include <map>
// #include <algorithm>

// using namespace std;
// map<int,int> m;

// int main(){
//     string s;
//     cin >> s;
//     for(char c : s){
//        m[(int)c] += 1;
//     }

//     for(int i = 97; i <= 122; i ++){
//         cout << m[i] << " ";
//     }
// }

#include <iostream>

using namespace std;
string s;
int cnt[26];

int main(){
    cin >> s;
    for(char c : s){
        cnt[c - 'a']++;
    }
    for(int i : cnt) cout << i << " ";
}
//https://www.acmicpc.net/problem/10808
// counting >> map or 배열로 해주는 것이 좋음
// 여기서는 아스키 코드를 사용해서 가능하니 할 필요없음
// 대문자 A>65 a>97
// sparse 하게 들어오거나, 배열의 개수가 1000만이 넘어가면 map을 생각해여함