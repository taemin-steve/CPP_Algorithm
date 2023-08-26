#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int a[3] = {1,2,3};
void makePermutation(int n,int r, int depth){
    if( r == depth) { 
        cout << a[0] << a[1] << a[2] << endl;
    }
    for(int i = depth; i < n; i++){
        swap(a[i], a[depth]);
        makePermutation(n,r, depth + 1);
        swap(a[i], a[depth]);// 원본으로 다시 돌아가주는 코드 
    }
}

int main(){
    cout << "Permutation" << endl;
    vector<int> v; 
    for(int i : a) v.push_back(i);

    do{
        cout << v[0] << v[1] << v[2] << endl;
    }while(next_permutation(v.begin(), v.end()));
    cout << endl;

    do{
        cout << v[0] << v[1] << v[2] << endl;
    }while(next_permutation(v.begin(), v.begin() + 2)); // 앞에 두개만 고치게 된다. 
    cout << endl;

    cout<< "unsorted case" << endl;
    int b[3] = {2,1,3};
    v.clear();
    for ( int i : b) v.push_back(i);

    do{
        cout << v[0] << v[1] << v[2] << endl;
    }while(next_permutation(v.begin(), v.end())); // 그 다음번째 순열을 만들어내기 때문에 정렬되지 않은 상태로 진행하면 문제가 발생할 수 있다. 
    cout<< endl;

    sort(v.begin(), v.end());
    do{
        cout << v[0] << v[1] << v[2] << endl;
    }while(next_permutation(v.begin(), v.end()));
    cout<< endl;

    do{
        cout<< a[0] << a[1] << a[2] << endl;
    }while(next_permutation(&a[0], &a[3]));
    
    do{
        cout<< a[0] << a[1] << a[2] << endl;
    }while(next_permutation(&a[0], &a[0] + 3));

    do{
        cout<< a[0] << a[1] << a[2] << endl;
    }while(next_permutation(a, a + 3)); // 위의 세개 모두 동일한 코드. 항상 시작 주소, 마지막 주소 +1 로 넣어주면 된다. 
    cout << endl;

    cout << "Permutation with Recur" << endl;
    makePermutation(3,3,0);
}