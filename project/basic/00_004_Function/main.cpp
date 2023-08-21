#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

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
    cout << endl;
    
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << "Unique" << endl;
    vector<int> v_unique;

    v_unique = {1,1,2,2,3,4,5};
    auto it = unique(v_unique.begin(), v_unique.end());
    for(int v : v_unique)cout << v ;
    cout << endl;

    v_unique = {3,3,5,3,2,3};
    it = unique(v_unique.begin(), v_unique.end());
    for(int v : v_unique){
        cout << v ;
    }
    cout << endl;

    it = unique(v_unique.begin(), v_unique.end());
    for(int v : v_unique)cout << v ;
    cout << endl;
    
    // 연속된 원소를 제거하는 것에 가까움! 따라서 sort()랑 같이 사용해 주어야 한다.
    sort(v_unique.begin(), v_unique.end());
    it = unique(v_unique.begin(), v_unique.end());
    for(int v : v_unique)cout << v ;
    cout << endl;

    //Erase 함수까지 사용하면 깔끔하게 중복되지 않은 요소만 돌려받을 수 있음!
    v_unique.erase(unique(v_unique.begin(), v_unique.end()), v_unique.end());
    for(int v : v_unique)cout << v ;
    cout << endl;

    ///////////////////////////////////////////////////////////////////////////////
    cout << "upper_bound(), lower_bound()" << endl;

    vector<int> v_bound = {1,3,5,7,9,11};
    cout << lower_bound(v_bound.begin(), v_bound.end(), 5) - v_bound.begin() << endl; // 5이상인 지점 반환
    cout << lower_bound(v_bound.begin(), v_bound.end(), 6) - v_bound.begin() << endl; // 6이상인 지점 반환
    cout << upper_bound(v_bound.begin(), v_bound.end(), 5) - v_bound.begin() << endl; // 5초과인 지점 반환

    cout << *lower_bound(v_bound.begin(), v_bound.end(), 5)<< endl; // 주소값이 리턴되기 때문에 역참조연산을 통해서 값확인가능
    
    v_bound = {1,3,3,3,9,11};
    //이를 활용하여 동일 원소의 개수를 구할 수도 있음!
    cout << upper_bound(v_bound.begin(), v_bound.end(), 3) - lower_bound(v_bound.begin(), v_bound.end(), 3)<< endl; // 주소값이 리턴되기 때문에 역참조연산을 통해서 값확인가능

    //해당 조건을 만족시키는 경우가 없는경우 근방 지점 리턴
    cout << upper_bound(v_bound.begin(), v_bound.end(), 13) - v_bound.begin() << endl; // 13초과인 부분이 없으므로, 그중에 조건에 가장 가까운 지점 리턴
    cout << endl;

    /////////////////////////////////////////////////////////////////////////////
    cout << "accumulate()" << endl;
    vector<int> v_acc = {1,2,3,4,5,6,7,8,9};
    int sum = accumulate(v_acc.begin(), v_acc.end(),0); //numeric lib을 import 해주어야 한다. 
    cout << sum << endl << endl;

    /////////////////////////////////////////////////////////////////////////////////
    cout << "max_element(), min_element" << endl;
    vector<int> v_mm = {1,2,3,4,5,6,7,8,9};
    cout << *max_element(v_mm.begin(), v_mm.end()) << endl; // 이터레이터가 반환되므로 역참조 연산으로 값 확인가능
    cout << max_element(v_mm.begin(), v_mm.end()) - v_mm.begin() << endl; // index 값 확인도 가능!

    cout << *min_element(v_mm.begin(), v_mm.end()) << endl; 
    cout << min_element(v_mm.begin(), v_mm.end()) - v_mm.begin() << endl;
}