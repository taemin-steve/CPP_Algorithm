#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>

using namespace std;

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

struct cmp{
    bool operator()(Point a, Point b){
        return a.x > b.x ; 
    }
};


int main(){
    cout << "Vector" << endl;
    vector<int> v;
    for( int i = 1; i <= 10; i++) v.push_back(i); 
    for( int a : v ) cout << a;
    cout << endl;

    v.pop_back(); // 백터의 가장 뒷부분 삭제
    for( int a : v ) cout << a;

    v.erase(v.begin(), v.begin() + 3); // erase의 경우 두번재 인자는 빼고 삭제!
    for( int a : v ) cout << a; // 범위기반 for loop의 경우 vector, array, map 모두 사용가능
    cout << endl;

    auto a = find(v.begin(), v.end(), 100);
    if(a == v.end()) cout << "not found" << endl;

    v.clear();
    if(v.size() == 0) cout << "noting" <<endl; // v.size() 함수는 vector의 함수임! array에 없다. 
    cout << endl; 

    vector<int> v_init(5,100); // size 5, value 100 
    for(int a : v_init) cout << a << " ";

    vector<vector<int>> v1;
    vector<vector<int>> v2(10, vector<int>(10,0)); // 이런식으로 바로 선언하는 것도 가능
    vector<int> v3[10];
    for( int i = 0; i < 10; i++){
        vector<int> temp;
        v1.push_back(temp);
    }
    cout << endl;

    /////////////////////////////////////////////////////////////////////////
    cout << "array"<< endl;
    int a1[3] = {1,2,3};
    int a2[] = {1,2,3};
    int a3[10];
    cout << sizeof(a1) << "," << sizeof(a2) << endl;

    const int mxy = 3;
    const int mxx = 4;
    int a_2d[mxy][mxx];
    for( int i = 0; i <mxy; i ++){
        for( int j = 0; j<mxx; j ++){
            a_2d[i][j] = (i+j);
        }
    }
    for( int i = 0; i <mxy; i ++){
        for( int j = 0; j<mxx; j ++){
            cout << a_2d[i][j] << " "; // x축으로 모두 탐색하고, 다음줄로 넘어가는것이 메모리 캐쉬측면에서도 좋다. 
        }
        cout << endl;
    }

    ///////////////////////////////////////////////////////////////////////////
    cout << "list" << endl;
    list<int> li;
    for(int i = 1; i <= 3; i++) li.push_back(i);
    for(int i = 1; i <= 3; i++) li.push_front(i); // 앞으로 삽입도 가능. O(1)
    for( int a : li) cout << a;
    cout << endl;

    auto it = li.begin(); // iterator는 보통 auto type으로 받아주는 것 같다. 
    it++ ;
    li.insert(it, 1000);
    for( int a : li) cout << a;
    cout << endl;


    li.erase(it); // insert 하면, 해당 iterator 앞에 추가되는 듯!
    for( int a : li) cout << a;
    cout << endl;

    li.pop_front();
    li.pop_back();

    for( int a : li) cout << a;
    cout << endl;

    li.clear();
    cout << endl;

    ///////////////////////////////////////////////////////////////////
    cout << " map " << endl;
    map<string, int> mp; // 페어 형태로 들어가는거 같은데.. 
    string s[3] = {"jtm", "kye", "lcw"};
    for(int i = 0; i < 3; i++){
        mp.insert(make_pair(s[i], i+1));
        mp[s[i]] = i + 1;
    }
    cout << mp["jtm"] <<endl;

    cout<< mp.size() <<endl; // size 사용가능 
    mp.erase("jtm");
    auto it_m = mp.find("jtm");
    if(it_m == mp.end()) cout << "no keys in there"<<endl << endl;

    mp["jtm"] = 100;
    it_m = mp.find("jtm");
    if(it_m != mp.end()){
        cout << (*it_m).first << " : " << (*it_m).second << endl;
    }
 
    for(auto it : mp) cout << it.first << " : " << it.first << endl; // 이경우는 그냥 바로 값을 준다. 
    cout << endl;
    for(auto it = mp.begin(); it != mp.end(); it ++) cout << (*it).first << " : " << (*it).second <<endl;

    cout << endl;
    mp["aaa"];
    cout << mp["aaa"] << endl<< endl; //자동으로 int 면 0으로 초기화됨
    if (mp["bbb"] == 0) cout << "right now, bbb is added";

    if(mp.find("kkk") == mp.end()){ // 이렇게 확인하는 것이 생성되는 것을 막을수 있다. 시간 복잡도는...?
        mp["kkk"]  = 10; 
    }
    cout << endl;

    ///////////////////////////////
    cout << "set()" << endl;
    set<pair<string, int>> st;
    st.insert({"this", 1});
    st.insert({"this", 1});
    st.insert({"this", 1});
    st.insert({"next", 1});
    cout << st.size()<< endl;
    for( pair<string,int> a : st) cout << a.first << endl;
    cout << endl;

    ///////////////////////////////////////////////
    cout <<"multiset" << endl;
    multiset<int> mst;
    for( int i = 1; i <= 5; i ++){
        mst.insert(i);
        mst.insert(i);
    }
    for( int a : mst) cout << a;
    cout << endl<<endl;

    ///////////////////////////////////////////////
    cout << "stack" << endl;
    stack<int> my_stack;
    for( int i = 1; i <= 5; i ++){
        my_stack.push(i);
    }
    while(my_stack.size()){ // cpp에서 0이면 거짓!
        cout << my_stack.top(); 
        my_stack.pop(); // 리턴이 안된다. 
    }
    cout << endl <<endl;

    ///////////////////////////////////////////////
    cout << "queue" << endl;
    queue<int> my_queue;
    for( int i = 1; i <= 5; i ++){
        my_queue.push(i);
    }
    while(my_queue.size()){ // cpp에서 0이면 거짓!
        cout << my_queue.front(); // stack은 top// queue 에서는 front
        my_queue.pop(); // 앞에서 부터 나옴! 
    }
    cout << endl;

    ///////////////////////////////////////////////////
    deque<int> dq;
    for( int i = 1; i <= 5; i ++){
        dq.push_back(i);
        dq.push_front(i);
    }
    for(int a : dq) cout << a;
    cout << endl;

    while(dq.size()){ 
        cout << dq.front(); 
        dq.pop_front(); 
        dq.pop_back(); 
    }
    cout << endl;
    
    ///////////////////////////////////////////////////
    cout << "priority queue" << endl; // true 이면 아래쪽으로 향하도록 로직이 짜여져 있는듯
    priority_queue<int> pq1; 
    priority_queue<int, vector<int>, greater<int>> pq2; // 여기서는 오름 차순. sort() 에서 cmp로 적용시 내림 차순
    priority_queue<int, vector<int>, less<int>> pq3;

    for(int i = 1; i<= 5; i++){
        pq1.push(i);
        pq2.push(i);
        pq3.push(i);
    }

    while(pq1.size()){
        cout << pq1.top() << " : " << pq2.top() << " : " << pq3.top() << endl;
        pq1.pop(); pq2.pop(); pq3.pop(); 
    }

    priority_queue<Point> pq_p;
    pq_p.push(Point(1,3));
    pq_p.push(Point(1,2));
    pq_p.push(Point(3,1));
    pq_p.push(Point(3,2));
    pq_p.push(Point(3,3));
    pq_p.push(Point(10,3));

    cout << pq_p.top().x << " " << pq_p.top().y << endl; // x가 제일 큰 10이 튀어나옴

    priority_queue<Point, vector<Point>, cmp> pq_c;
    pq_c.push(Point(1,3));
    pq_c.push(Point(1,2));
    pq_c.push(Point(3,1));
    pq_c.push(Point(3,2));
    pq_c.push(Point(3,3));
    pq_c.push(Point(10,3));

    cout << pq_c.top().x << " " << pq_c.top().y << endl; // x기준 가장 작은것. 그 뒤로 y기준 작은거 튀어나옴 >> 1,2


}