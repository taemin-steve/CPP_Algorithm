#include <iostream>
#include <map>

using namespace std;

int N, M, gou, ans;
map<int,int> mp;

int main(){
    cin >> N >> M;

    for(int i=0; i < N; i++){
        cin >> gou;
        mp[gou]++;
    }

    for(auto i : mp){
        if(mp.find(M - i.first) != mp.end()){
            ans += min(mp[M - i.first], mp[i.first]);
        }
    }
    cout << ans/2;
}