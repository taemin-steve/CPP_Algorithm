#include <iostream>
#include <vector>
using namespace std;

void change_a1(int a[]){a[2] = 10;} // 가변배열로
void change_a2(int a[3]){a[2] = 100;}// 크기를 정한 배열로
void change_a3(int *a){a[2] = 100;}// 포이터로 받아서 진행 가능
void change_a_2d(int a[][3]) {a[0][0] = 10000;} // 랜덤으로 할 수 있는건 가장 앞단만!

void change_v1(vector<vector<int>> &v){v[0][0] = 9;}
void change_v2(vector<int> v[5]){ v[0][0] = 99;} // vector<int> 를 원소로 가지는 v라는 배열로 해석하는 경우

int main(){
    int a[3] = {1,2,3};
    change_a1(a); cout << a[2] << endl;
    change_a2(a); cout << a[2] << endl;
    change_a3(a); cout << a[2] << endl;

    vector<vector<int>> v(5, vector<int>(5,1));
    for (vector<int> a : v){
        for (int b : a){
            cout << b;
        }
        cout << endl;
    }
    change_v1(v);
    for (vector<int> a : v){
        for (int b : a){
            cout << b;
        }
        cout << endl;
    }

    vector<int> v2[5];
    v2[0].push_back(0);
    change_v2(v2);
    for (vector<int> a : v2){
        for (int b : a){
            cout << b;
        }
    }

    int a_2d[3][3] = {{1,2,3}, {1,2,3}, {1,2,3}};
    change_a_2d(a_2d);
    for (const auto& row : a_2d) {
       for (int v : row) {
           std::cout << v;
       }
    }

}