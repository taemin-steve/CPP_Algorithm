#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
int N;
string s;
map<char, int> m;
vector<char> v;

int main(){
    //N번 반복
    cin >> N;
    for(int i =0; i < N; i++){
        // 문자열 String에 담고 
        cin >> s;
        // 각각의 배열을 슬라이싱 해서 Map에 저장 밎 카운팅 
        m[s[0]] += 1;
    }
    // Map 순회하면서 5 이상인 경우 ret에 저장
    for(auto item : m){
        if(item.second >= 5){
            v.push_back(item.first);
        }
    }
    //sort 하고 출력 
    sort(v.begin(), v.end());
    if(v.size() == 0){ // v.size()는 vector의 내장함수! 
        cout << "PREDAJA";
    }
    else for(char c : v) cout << c;
}
//https://www.acmicpc.net/problem/1159