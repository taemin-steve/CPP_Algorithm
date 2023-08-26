#include <iostream>

using namespace std;

int factorial(int n){
    if (n == 0 || n == 1) return 1;
    return n * factorial(n-1);
}
int main(){
    cout << "Factorial" << endl;
    cout << factorial(5) << endl << endl;
}