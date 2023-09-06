// # include <iostream>

// using namespace std;

// int N;
// string tpl, temp, s;
// int pos_star;
// int pos_string;

// int main(){
//     cin >> N;
//     cin >> tpl;

//     // 사전 작업으로 *의 위치 확인
//     pos_star = tpl.find("*");

//     for(int i=0; i < N; i++){// 각각의 입력에 대해 반복
//         cin >> s;
//         temp = "";

//         if(s.length() < tpl.length() - 1){
//             cout << "NE" << endl; 
//             continue;
//         } 

//         for(int j = 0; j < pos_star; j++){
//             temp += s[j];
//         }

//         temp += "*";
//         int number = tpl.length() - pos_star - 1;
//         pos_string = s.length() - number; // string에서 시작하고 싶은 위치 

//         for(int k = 0; k < number; k++){
//             temp += s[pos_string + k];
//         }

//         if(temp == tpl) cout << "DA" << endl;
//         else cout << "NE" << endl;
//     }
// }  //https://www.acmicpc.net/problem/9996

#include <iostream>

using namespace std;
int N;
string s, ori, sub, pre;

int main(){
    cin >> N;
    cin >> ori;

    int pos_aster = ori.find("*");
    pre = ori.substr(0, pos_aster);
    sub = ori.substr(pos_aster + 1);


    for(int i=0; i < N; i++){
        cin >> s;
        if(s.size() < pre.size() + sub.size()) cout << "NE" << endl;
        else{
            if(s.substr(0,pos_aster) == pre && s.substr(s.size() - sub.size()) == sub) cout << "DA" << endl;
            else cout << "NE" << endl;
        }
    }
}
