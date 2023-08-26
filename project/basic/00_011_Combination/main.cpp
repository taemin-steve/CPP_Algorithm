#include <iostream>
#include <vector>

using namespace std;

int n = 5, k=3, a[5] = {1,2,3,4,5};

void print(vector<int> &v){
    for(int i : v) cout << i;
    cout << endl;
}

void combination(int n , int k, int start , vector<int> &b){// 이렇게 계속 레퍼런스로 타고 들어가도 되는건가?
    if(b.size() == k){
        print(b);
        return;
    }
    for(int i = start + 1; i < n ; i++){
        b.push_back(a[i]);
        combination(n,k, i, b);
        b.pop_back();
    }
    return;
}


int main(){
    vector<int> b;
    combination(n, k, -1, b);
    return 0;
}