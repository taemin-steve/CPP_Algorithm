#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
int a[9];

vector<int> combi(int n, int k, int start, vector<int> &v){
    if(v.size() == k){
        if( 100 == accumulate(v.begin(), v.end(), 0))
        return v;
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
    
    vector<int> ans = combi(9, 7, 0, v);
    for( int i : ans) cout << i << endl;
}   