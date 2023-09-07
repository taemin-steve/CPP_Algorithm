#include <iostream>
#include <map>
#include <string>
#include <unordered_map>

using namespace std;

int M, N;
string p_array[100010];
map<string,int> m;
string s;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL); // 이거 차이 엄청 크다

    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        cin >> p_array[i];
        m[p_array[i]] = i;
    }

    for(int j = 0; j < M; j++){
        cin >> s;
        if(m.find(s) == m.end()){ //map에 없으면 
            cout << p_array[atoi(s.c_str())] << "\n";
            continue;
        }
        else cout << m[s]<< "\n";
    }
}