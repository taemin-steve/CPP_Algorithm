#include <iostream>

using namespace std;

int fact_rec(int n){
    if(n==1 || n==0) return 1;
    return n * fact_rec(n-1);
}

int fact_int(int n){
    int ret = 1;
    for(int i = 1; i <= n ; i++){
        ret *= i;
    }
    return ret;
    
}

int main(){
    int n = 5;
    cout << fact_rec(n)<< '\n';
    cout << fact_int(n)<< '\n';

}