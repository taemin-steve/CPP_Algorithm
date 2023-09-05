#include <iostream>
#include <vector>

using namespace std;
string s;
int l, r;
int ans = 1;

int main(){
    //문자열 string으로 받고 
    cin >> s;
    //two pointer 선언
    l = 0;
    r = s.length() - 1;
    //two pointer로 양쪽 확인하면서 진행 
    while (l < r){
        if(s[l] == s[r]){
            l++; r--;
            continue;
        }
        else{
            ans = 0;
            break;
        }
    }
    cout << ans;
}
//https://www.acmicpc.net/problem/10988