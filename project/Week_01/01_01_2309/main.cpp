#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;
// int a[9];
// vector<int> ans;

// void combi(int n, int k, int start, vector<int> &v){
//     if(v.size() == k){
//         if( 100 == accumulate(v.begin(), v.end(), 0)){
//             ans =  v;
//         }
//     }
//     for(int i = start + 1; i < n; i++ ){
//         v.push_back(a[i]);
//         combi(n,k,i,v);
//         v.pop_back();
//     }
// }

// int main(){
//     vector<int> v;

//     for(int i = 0; i < 9; i++){
//         cin >> a[i];
//     }
//     cout << endl;

//     combi(9, 7, -1, v);
//     sort(ans.begin(), ans.end());
//     for( int i : ans) cout << i << endl;

// }  

///// 좀더 효율적인 코드 반대로 생각하기 
int a[9];
int sum = 0;
pair<int,int> p;

void solve(){
    for(int i =0; i < 9; i++){
        for(int j=i+1; j < 9; j++){
            if(sum - a[i] - a[j] == 100) p = {i,j};
        }
    }
}


int main(){
    for(int i =0; i < 9; i++){
        cin >> a[i];
        sum += a[i];
    }
    solve();
    vector<int> ans;
    for(int i=0; i < 9; i++){
        if(i == p.first || i == p.second){
            continue;
        }
        else{
            ans.push_back(a[i]);
        }
    }
    sort(ans.begin(), ans.end());
    for(int i : ans) cout << i << endl;
}