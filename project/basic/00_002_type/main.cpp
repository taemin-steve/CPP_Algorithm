#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
vector<string> split(string input, string delimeter){
    vector<string> ret;
    string token = "";
    long long pos = 0;
    while((pos = input.find(delimeter)) != string::npos){
        token = input.substr(0,pos);
        ret.push_back(token);
        input.erase(0,pos + delimeter.length());
    }
    return ret;
}

int main(){
    //string type ------------------------------------------------
    // string a = "love is";
    // a += " pain!";
    // a.pop_back();

    // cout << a << " : " << a.size() << "\n";
    // cout << char(* a.begin()) << "\n"; // begin >> 첫번째 이터레이터를 반환
    // cout << char(* (a.end() - 1)) << "\n";

    // a.insert(0, "test ");
    // cout << a << " : " << a.size() << "\n";
    // a.erase(0,5); // 0번째 부터 5번째 전까지 삭제 
    // cout << a << " : " << a.size() << "\n";
    
    // auto it = a.find("love"); // 찾는값이 없음면 string::npos를 리턴해줌
    // if (it != string::npos){
    //     cout << "포함되어 있다." << "\n";
    // }

    // cout << it << "\n";
    // cout << string::npos << "\n";
    // cout << a.substr(5,2) << "\n";

    //아스키 코드 --------------------------------------------------------
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout.tie(NULL);
    // char a = 'a'; // 소문자 a는 아스키 코드로 97 // 대문자는 65
    // cout << (int)a << "\n"; // > 97이 튀어나온다 // 문자열의 경우 다음과 같이 conversion operator 없이 바로 바꾸는것은 불가능 파이썬만 가능한듯.

    // Reverse---------------------------------------------------------------
    // String에는 없어서 STL 사용해야함. 원본 문자열을 바꿔버린다. 
    string r = "abcdefghi";
    reverse(r.begin() + 3, r.end());
    cout << r << "\n";

    // define split--------------------------------------------------------
    // string s = " abv des gew dw";
    // vector<string> a = split(s, " ");
    // for(string b : a) cout << b << "\n"; // 범위기반 for 루프. vector에 대해서 쉽게 반복 사용가능

    //string to int---------------------------------------------------------
    // vector<string> v = {"15", "wef"};
    // for(string a : v) cout << a.c_str()<< "\n"; // c_str()을 해주는 이유는 각 원소의 뒤에 "\n"을 붙여주기 위함인듯.
    // for(string a : v) cout << atoi(a.c_str())<< "\n"; // 내용이 변경되면 안 되는 제약 조건을 가진, char형 포인터를 리턴합니다

    // CPP 에서는 0이면 false // 나머지는 모두 참. 
    int  a= -1;
    cout << bool(a) << "\n"; // bool() >> True, False로 바꾸어 주는데, 0아니면 모두 참이니깐 참인 1로 변경 해줌
    a = 0;
    cout << bool(a) << "\n"; //  a가 0이면 
    a = 1;
    cout << bool(a) << "\n";
    cout << true << "\n"; // true == 1

    pair<int, int> pi;
    tuple<int, int, int> t1; // tuple 을 써주고 싶으면 위에서 include 해야한다. 
    int k, b, c;
    pi = {4,5};
    t1 = make_tuple(1,2,3);
    tie(k,b,c) = t1; // tie를 쓰지 않는 경우.. 상당히 복잡해 지니.. 그냥 tie 씁시다.
    cout << k << b << c << endl;
    tie(k,b) = pi;
    cout << k << b << endl;
    

    // auto >> 스스로 추론해서 타입을 정하는 방식. 주로 길고 어려운 변수 타입을 쓸때 활용하기도 한다. 
    vector<pair<int,int>> v;
    for(int i = 1; i <= 5; i++){
        v.push_back({i,i});
    }
    for(auto it : v){
        cout << it.first << ":" << it.second << endl;
    }

    return 0;
}