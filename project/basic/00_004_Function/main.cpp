#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    return a.second < b.second; // 참인 경우 순서 유지!! a < b 인경우, a가 그대로 앞으로 유지 
}

int main(){
    ///////////////////////////////////////////////////////////////////////////
    cout << "fill()" << endl; // 모든 값으로 초기화 가능 
    int a[10];
    int b[10][10];

    fill(&a[0], &a[10], 100); // fill은 시작값 포함, 마지막 값 미포함이다. 
    for(int k : a){
        cout << k << endl;
    }
    fill(&b[0][0], &b[9][10], 7);
    for(int i=0; i < 10; i++){
        for(int j=0 ; j <10; j++){
            cout << b[i][j];
        }
        cout << endl;
    }
    cout << endl;

    ///////////////////////////////////////////////////////////////////////////////////
    cout << "memset()" << endl; // 0,-1, char형 문자 하나 정도로 초기화 가는ㅇ 
    memset(b, 0 , sizeof(b)); // 배열 이름, 원하는 수, 크기가 끝임
    for(int i=0; i < 10; i++){
        for(int j=0 ; j <10; j++){
            cout << b[i][j];
        }
        cout << endl;
    }
    cout << endl;

    ///////////////////////////////////////////////////////////////////////////
    cout << "memcpy(dest, source, size)" << endl;
    int c[3] = {1,2,3};
    int ret[3];
    memcpy(ret, c, sizeof(c));
    cout << ret[2] << endl;
    ret[2] = 1;
    cout << ret[2] << endl;
    cout << c[2] << endl << endl; // 깊은 복사가 진행되기 때문에 원본이 변하지는 않는다.

    /////////////////////////////////////////////////////////////////////////////////////
    cout << "copy(first, last, result)" << endl;
    vector<int> v = {1,2,3};
    vector<int> v_ret(sizeof(v)); // 복사당할 Vector의 크기를 맞춰 주어야 함
    copy(v.begin(), v.end(), v_ret.begin());
    cout << v_ret[2] << endl << endl;
    
    /////////////////////////////////////////////////////////////////////////////////////
    cout << "sort(first, last, cmp)" << endl;
    vector<int> v_sort = {2,1,5,6,3};
    for(int v : v_sort){ cout << v << " ";}
    cout << endl;

    sort(v_sort.begin(), v_sort.end()); // 기본적으로 오름차순으로 정렬
    for(int v : v_sort){ cout << v << " ";} 
    cout << endl;

    sort(v_sort.begin(), v_sort.end(), greater<int>()); // cmp 자리에 greater<타입>() 제공하여 내림차순으로 가능
    for(int v : v_sort){ cout << v << " ";} 
    cout << endl<<endl;

    vector<pair<int,int>> v_sort_pair;
    for(int i=1; i < 10; i++)v_sort_pair.push_back({i, 10-i});
    for(pair<int,int> v : v_sort_pair){ cout << v.first << "," << v.second << endl;}
    cout << endl;

    sort(v_sort_pair.begin(), v_sort_pair.end()); // pair 가 들어가는경우 자체적으로 첫번째, 두번째 기준으로 정렬됨 
    for(pair<int,int> v : v_sort_pair){ cout << v.first << "," << v.second << endl;}
    cout << endl;

    sort(v_sort_pair.begin(), v_sort_pair.end(), cmp); // cmp적용 
    for(pair<int,int> v : v_sort_pair){ cout << v.first << "," << v.second << endl;}


}