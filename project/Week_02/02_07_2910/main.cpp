// 기본적으로 Map 함수 써서 진행하고 싶은데, 먼저 나온게 앞에있어야 하는게 좀 까다로워
// 사실 시간복잡도 상으로는 그냥 find 때려도 무방하긴한데... 
// 첫번째로 들어간 경우에 같이 넣어주지 뭐!

#include <bits/stdc++.h>

using namespace std;
int N, C, arr[1001];
map<int, pair<int,int>> m;

bool comp(pair)

int main(){
    cin >> N >> C;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    for(int i=0; i<N; i++){
        if(m.find(arr[i]) != m.end()){
            m[arr[i]] = {0,i};
        }
        else{
            m[arr[i]].first += 1;
        }
    }
    sort(m.begin(), m.end(), comp);

    
}