#include <iostream>
#include <vector>
using namespace std;

vector<string> split(string input, string delimeter){
    vector<string> ret;
    long long pos = 0;
    string token = "";
    while( (pos = input.find(delimeter)) != string::npos){
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos + delimeter.length());
    }
    return ret;
}

int main(){
    string s = "Hello my name is EHmin " , d = " ";
    vector<string> a = split(s,d);
    for(string b : a) cout << b << "\n";
}