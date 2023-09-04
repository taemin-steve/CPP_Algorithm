#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
map<int,int> m;

int main(){
    string s;
    cin >> s;
    for(char c : s){
       m[(int)c] += 1;
    }

    for(int i = 97; i <= 122; i ++){
        cout << m[i] << " ";
    }
}
//https://www.acmicpc.net/problem/10808