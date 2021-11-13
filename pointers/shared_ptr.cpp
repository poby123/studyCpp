#include<iostream>
#include<memory>
#include<cstring>
#include<chrono>
using namespace std;

class Person{
    char* name = nullptr;

public:
    Person(const char* name){
        this->name = new char [strlen(name)+1];
        strcpy(this->name, name);
    }

    ~Person(){
        cout << "소멸자 호출!\n"; 
        if(name != nullptr){
            delete[] name;
            name = nullptr;
        }
    }

    friend ostream& operator<<(ostream& os, Person& p){
        os << p.name << "\n";
        return os;
    }
};

int main(){
    /* Ch-01: 기본 사용법 */
    shared_ptr<Person> p1(new Person("철수"));
    cout << *p1;
    cout << "p1 ref count : " << p1.use_count() << "\n\n"; // 1


    shared_ptr<Person> p2 = p1;
    cout << *p2;
    cout << "p1 ref count : " << p1.use_count() << "\n"; // 2
    cout << "p2 ref count : " << p2.use_count() << "\n"; // 2
    cout << "\n";

    /* Ch-02: make_shared : 더 빠른 생성이라고 했는데 왜 더 느리지??*/
    auto start = std::chrono::system_clock::now();
    shared_ptr<Person> s1(new Person("짱구"));      
    auto end = std::chrono::system_clock::now();
    auto nano  = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    cout << "짱구 생성 속도 : " << nano.count() << "\n"; // 311 nanoseconds
    
    start = std::chrono::system_clock::now();
    shared_ptr<Person> s2 = make_shared<Person>("영희");
    end = std::chrono::system_clock::now();      
    nano  = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    cout << "영희 생성 속도 : " << nano.count() << "\n"; // 1038 nanoseconds
    cout << endl;

    /* Ch-03: 주의사항 */
    Person *a = new Person("AAA");
    shared_ptr<Person>sptr1(a);
    shared_ptr<Person>sptr2(a);
    cout << "(sptr1 == sptr2) : " << (sptr1 == sptr2) << "\n"; // 같은 객체를 가리키지만
    cout << "sptr1 ref count : " << sptr1.use_count() << "\n"; // ref count는 1
    cout << "sptr2 ref count : " << sptr2.use_count() << "\n"; // ref count는 1
    cout << endl;
    // => shared_ptr을 생성할 때 객체의 주소값을 넘기면, ref count를 저장하는 제어블록이 따로 생겨서
    // ref count 가 동기화되지 않고, 런타임 오류가 발생할 수 있다.

    return 0;
}