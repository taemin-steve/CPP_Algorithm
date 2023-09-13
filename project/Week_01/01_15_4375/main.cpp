#include <iostream>

using namespace std;

int n;

int main(){
	while(scanf("%d", &n) != EOF){
		int cnt = 1;
		int number_one = 1;
		while(true){
			if (number_one % n == 0){
				printf("%d\n", cnt);
				break;
			} 
			else{
				number_one = number_one * 10 + 1;
				number_one %= n;
				cnt ++; 
			}
		}
	}
	return 0;
}