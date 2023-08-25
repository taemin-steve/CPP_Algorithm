#include <iostream>
#include <vector>
using namespace std;

void call_v(int a){a = 10;}
void call_r(int& a){a = 10;}
void call_r(vector<int> &v){ v.push_back(10);}


int main(){
    int a = 0;
    cout << a <<endl;

    call_v(a);
    cout << a << endl;

    call_r(a);
    cout << a << endl;

    vector<int> v;
    v.push_back(1);
    for(int a : v) cout << a << endl;

    call_r(v);
    for(int a : v) cout << a << endl;
}