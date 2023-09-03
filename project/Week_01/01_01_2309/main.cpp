#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;
int a[9];
vector<int> ans;

void combi(int n, int k, int start, vector<int> &v){
    if(v.size() == k){
        if( 100 == accumulate(v.begin(), v.end(), 0)){
            ans =  v;
        }
    }

    for(int i = start + 1; i < n; i++ ){
        v.push_back(a[i]);
        combi(n,k,i,v);
        v.pop_back();
    }

}

int main(){
    vector<int> v;

    for(int i = 0; i < 9; i++){
        cin >> a[i];
    }
    cout << endl;

    combi(9, 7, -1, v);
    sort(ans.begin(), ans.end());
    for( int i : ans) cout << i << endl;
}   