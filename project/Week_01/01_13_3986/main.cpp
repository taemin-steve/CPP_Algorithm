#include <iostream>
#include <stack>

using namespace std;  
int n, ret; 
string s; 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n; 
	for(int i = 0; i < n; i++){
		cin >> s; 
		stack<char> stk;
		for(char a : s){
			if(stk.size() && stk.top() == a)stk.pop(); // Stack에서 top, pop등을 할때 반드시 존재 하는지확인부터 해줘야한다 !
			else stk.push(a);
		} 
		if(stk.size() == 0)ret++;
	}
	cout << ret << "\n"; 
}// https://www.acmicpc.net/problem/3986

// 문제를 보고 모르겠으면 뒤집거나, 회전시켜보거나, 더 붙여 보자 
// 두개가 만나면 터져 버리는 구조가 되면 좋을듯!
// 짝짓기, 폭팔등이 있다면 stack의 구조일 가능성이 높다.
