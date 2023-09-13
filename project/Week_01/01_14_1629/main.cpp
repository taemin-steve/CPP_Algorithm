#include <iostream>
#include <algorithm>

using namespace std;
int A, B, C;

int main(){
	cin >> A >> B >> C;

	A = A % C;

	cout << pow(A,B) % C;	
}