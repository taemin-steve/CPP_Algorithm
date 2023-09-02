#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rotate_left_90(vector<vector<int>> &key){
    int n = key.size();
    int m = key[0].size();

    vector<vector<int>> temp(m , vector<int>(n,0));
    for( int i =0; i < m; i++){
        for(int j=0; j < n; j++){
            temp[i][j] = key[j][m-i-1];
        }
    }
    key.resize(m);
    key[0].resize(n);

    key = temp;
    return ;
}

int main(){
    vector<int> v = {1,2,3,4,5};
    rotate(v.begin(),v.begin()+ 1, v.end()); // 첫번째 인자는 그냥 시작점. 두번째 인자는 처음으로 만들고 싶은 원소!
    for(int i : v) cout << i;
    cout << endl;
    
    v = {1,2,3,4,5};
    rotate(v.begin(), v.begin() + 2, v.begin()+ 4); // 5는 계속 맨뒤에 존재 
    for(int i : v) cout << i;
    cout << endl;

    v = {1,2,3,4,5};
    rotate(v.rbegin(),v.rbegin()+ 1, v.rend()); // 반대로 rotate 시키는 경우 
    for(int i : v) cout << i;
    cout << endl<< endl;

    cout << "rotate" << endl;
    vector<vector<int>> v_2d = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };
    rotate_left_90(v_2d);
    for(vector<int> v : v_2d){
        for(int i : v) cout << i << " ";
        cout << endl;
    }
    cout << endl;

    cout << "nary" << "\n";
    int n = 111;
    int nary = 16;
    vector<int> v_nary;
    while( n > 1){
        v_nary.push_back(n % nary);
        n /= nary;
    }
    if( n == 1) v_nary.push_back(1);
    reverse(v_nary.begin(), v_nary.end());
    for(int i : v_nary){
        if(i > 10) cout << char( i + 55);
        else cout << i;
    }
}