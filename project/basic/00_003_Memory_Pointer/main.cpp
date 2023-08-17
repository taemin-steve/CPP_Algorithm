#include <iostream>

using namespace std;

int main(){
    cout << "Memory & Pointer" << endl;

    int i = 10;
    cout << &i << endl ; // &는 일반변수 앞에서 사용될 때 일반변수의 주소를 리턴! >> 값이 변한다고 해서 변하지 않음

    int *p = &i; // (변수타입)* 포인터 변수  << 이렇게 선언. 
    cout << p << endl;

    cout << *p << endl << endl;  // *(에스터리스크) 기호가 이와 같이  pointer 변수에게 붙으면 역참조 연산자가 되어 해당 pointer 변수의 주소에 저장된 값이 제공

    
    cout << "Array to Pointer decay" << endl;
    int array[3] = {1,2,3};
    int *pa = array;
    cout << pa << endl;
    cout << array << endl;
    cout << pa + 1 << endl;
    cout << &array[1] << endl << endl;

    cout << "Memory allocation" << endl;

    /// 정적 할당 : 컴파일 단계에서 메모리 할당. 
    // BSS segment: 전역, static, const 변수중 0으로 초기화, 혹은 초기화가 진행되지 않은 변수들이 할당.
    // Code/Text Segment: 프로그램의 코드가 돌아감

    /// 동적 할당 : 런타임 단계에서 메모리 할당.
    // Stack : 지역변수, 매개변수, 함수등에 의해 늘어나거나 줄어드는 메모리 영역. 함수 내의 변수 집합이 해당 함수의 다른 인스턴스 변수를 방해하지 않음
    // Heap : 동적으로 할당되는 변수를 담음. malloc, free 함수로 관리됨. vector가 대표적인 예시
}