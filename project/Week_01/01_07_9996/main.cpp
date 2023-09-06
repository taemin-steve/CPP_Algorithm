#include <iostream>
#include <vector>

using namespace std;

int N;
string pattern;
string s;
int i=0, j =0;
int margin;
vector<string> v;


int main(){
    cin >> N >> pattern;
    for(int k = 0; k < N ; k ++){
        cin >> s;
        i = 0; j = 0; //초기화 

        for(int l = 0; l < pattern.length(); l++ ){
            if( l == pattern.length()-1){
                v.push_back("DA");
                break;
            }
            if(pattern[j] == '*'){
                margin = pattern.length() - j; 
                i = s.length() - margin ;
                i++; j++;
                continue;
            }
            else if(s[i] == pattern[j]){
                j++; i++;
                continue;
            }
            else{
                v.push_back("NE");
                break;
            } 
        }
    }
    for(string ans : v) cout << ans << endl;
} 
// 
.