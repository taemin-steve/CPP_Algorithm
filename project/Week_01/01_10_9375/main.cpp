#include <iostream>
#include <map>

using namespace std;

int N, M, ans;
string name, type;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> M;
        map<string, int> mp;
        ans = 1;
        for(int j=0; j < M ; j++){
            cin >> name >> type;
            mp[type] += 1;
        }
        for(auto item : mp){
            ans *= (item.second +1);
        }
        cout << ans -1 << "\n"; // 여러개 있는 경우에 공백문자 반드시 포함해 주어야 한다 
    }
}