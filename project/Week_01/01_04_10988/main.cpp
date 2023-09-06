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
// 이런경우 그냥 거꾸로 reverse 해서 확인하면 끝난다!
// #include<bits/stdc++.h>
// using namespace std;   
// string s, temp; 
// int main(){
//     cin >> s; 
//     temp = s; 
//     reverse(temp.begin(), temp.end()); 
//     if(temp == s) cout << 1 << "\n"; 
//     else cout << 0 << "\n"; 
      
//     return 0; 
// }