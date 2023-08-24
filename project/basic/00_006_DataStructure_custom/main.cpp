#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct my_structure{
    int a, b;
    double c,d,e;
};

struct Point
{
    int x, y;
    Point(int x, int y) : x(x), y(y){}
    Point() {x = -1; y = -1;}

    bool operator < (const Point & other) const{// 항상 조건을 만족해주는 놈이 앞으로 가게 된다고 생각하자
        if (x == other.x) return y > other.y; // y 에 대한 내림 차순 
        return x < other.x; // x 에 대한 오름차순  
    }
};

bool cmp(const Point &a, const Point &b){
    return a.x > b.x; // 내림 차순으로 정렬
}


void print(my_structure s){
    cout << s.a << " " << s.b << " " << s.c << " " << s.d << " " << s.e << endl; 
}

int main(){
    my_structure s = {1,2,3,4,5};
    print(s);
    vector<my_structure> v ; // vector에 담는 것도 가능
    v.push_back(s);
    v.push_back(s);
    for( my_structure s : v) print(s);
    cout << endl;

    vector<Point> v_p;
    v_p.push_back(Point(1,3));
    v_p.push_back(Point(1,2));
    v_p.push_back(Point(3,1));
    v_p.push_back(Point(3,2));
    v_p.push_back(Point(3,3));
    v_p.push_back(Point(10,3));

    sort(v_p.begin(), v_p.end());
    for( Point p : v_p) cout << p.x << " " << p.y << endl;

    sort(v_p.begin(), v_p.end(), cmp); // 이렇게 하는 경우 정의 되지 않은 두번재 기준은 기존의 기준을 따르게 된다. 
    for( Point p : v_p) cout << p.x << " " << p.y << endl;
}