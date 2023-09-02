#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b){ // Great Common Divisor, 유클리디안 호제법을 이용
    if(a==0) return b;
    return gcd(b % a, a); 
}

int lcm(int a, int b){
    return (a * b)/gcd(a,b);  
}

const int max_n = 40;
bool che[max_n + 1];

vector<int> era(int mx_n){ // 에라토스테네스의 채 , 배수를 지워나가는 방식 
    vector<int> v;
    for( int i = 2; i <= mx_n; i++){
        if(che[i]) continue;
        for( int j = 2*i; j <= mx_n; j+= i){
            che[j] = 1;
        }
    }
    for( int i = 2; i <= mx_n; i++) if(che[i] == 0 ) v.push_back(i);
    return v;
} // 해당 방식은 메모리를 잡아먹기 때문에, 특정 크기 이상에서는 사용하기가 어려움!

bool check(int n){ // 이렇게 하나하나 직접 해주는 코드도 알고 있는것이 좋음. 
    if( n <= 1) return 0;
    if( n == 2) return 1;
    if( n % 2 == 0) return 0;
    for( int i =2 ; i*i <=n ; i ++){
        if( n % i == 0) return 0;
    }
    return 1;
}

int main(){
    int a = 12;
    int b = 4;
    cout << gcd(a, b) << endl;
    cout << lcm(a, b) << endl << endl;

    cout<<"prime number" << endl;
    vector<int> p = era(max_n);
    for(int i : p) cout << i;
    cout << endl << endl;

    cout << "geometric sequence" << endl;
    int start = 1, r = 2, n = 4;
    cout << start * ((int)pow(2,n) - 1)/ (r-1)<< endl << endl;

    cout << "sqrt" << endl;
    cout << sqrt((int)pow(2, 4))<<endl;

}