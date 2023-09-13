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
    // if(m > 20000) cout << 0 << cout; 시간 초과가 빡센경우 에외처리가 가능하다면 진행해 주자!
    for(auto i : mp){
        if(mp.find(M - i.first) != mp.end()){ // 세개까지는 그냥 콤비네이션 하자!
            ans += min(mp[M - i.first], mp[i.first]);
        }
    }
    cout << ans/2;
}