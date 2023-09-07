#include <iostream>
#include <algorithm>
using namespace std;

string s, ans;
int cnt[26];
string center;
int odd_count = 0;

int main(){
    cin >> s;
    for(char c : s){
        cnt[c - 65] += 1;
    }

    for(int i = 0; i < 26; i ++ ){
        if(cnt[i] == 0) continue;
        if(cnt[i] % 2 == 0){
            for(int j = 0 ; j < (cnt[i]/2); j ++) ans += ((char)(i + 65));
        }
        else{
            center = ((char)(i + 65));
            for(int j = 0 ; j < ((cnt[i] - 1)/2); j ++) ans += ((char)(i + 65));
            odd_count++;
        }
    }

    if(odd_count == 0){
        string temp = ans;
        reverse(ans.begin(), ans.end());
        cout << temp + ans;
    } 
    else if(odd_count == 1){
        string temp = ans;
        reverse(ans.begin(), ans.end());
        cout << temp + center + ans;
    } 
    else cout << "I'm Sorry Hansoo";
}