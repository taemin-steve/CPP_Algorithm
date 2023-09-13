#include <iostream>
#include <algorithm>

typedef long long ll;

using namespace std;
int A, B, C;

int DP(ll a, ll b){
	if(b == 1) return a % C;

	ll ret = DP(a, b/2) ;
	ret = (ret * ret) % C; // 이미 계산한 것을 사용해 주자!
	if(b % 2 != 0) ret = (ret * a) % C;
	return ret; 
}

int main(){
	cin >> A >> B >> C;

	cout << DP(A,B) << endl;

	return 0;
}

// (a*b) % c == (a%c) * (b%c)