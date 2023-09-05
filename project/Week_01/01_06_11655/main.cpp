#include <iostream>
#include <string>
#include <vector>

using namespace std;

string s;
vector<char> v;

int main(){
    // 줄단위로 문자열을 받고, getline 
    getline(cin, s);

    for(char c : s){
        if( c >= 65 && c <= 90){
            c = c - 'A';
            c += 13;
            c %= 26;
            c = c + 'A';
            v.push_back(c);
        }
        else if( c >= 97 && c <= 122){
            c = c - 'a';
            c += 13;
            c %= 26;
            c = c + 'a';
            v.push_back(c);
        }
        else v.push_back(c);
    }
    
    for(char c : v) cout << c;
}