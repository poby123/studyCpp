#include<iostream>
#include<memory>
#include<cstring>
#include<vector>
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
        if(name != nullptr){
            delete[] name;
        }
    }

    friend ostream& operator<<(ostream& os, Person& p){
        os << p.name << "\n";
        return os;
    }
};

int main(){
    unique_ptr<Person> p(new Person("철수"));
    cout << *p;

    // -> 오류 소유권을 유일하게 유지하기 위해서 unique_ptr의 복사생성자를 막아놓았다.
    // unique_ptr<Person> p2 = p;


    // -> 소유권의 이동은 가능하다. 원래의 p는 nullptr이 된다.
    unique_ptr<Person> p3 = move(p);
    cout << *p3;
    cout << "(p == nullptr) : " << (p == nullptr) << "\n\n"; // 1

    // -> 컨테이너의 사용
    vector<unique_ptr<Person>> v;
    // v.push_back(p3); // push_back을 호출하면 복사생성자가 호출되므로 오류가 발생한다.
    v.push_back(move(p3)); // 소유권을 이전하거나
    v.emplace_back(new Person("영희")); // emplace_back을 이용하면 된다.
    v.push_back(unique_ptr<Person>(new Person("짱구"))); // 윗줄은 이거와 같은 의미가 된다.
        
    for(int i=0;i<v.size();i++){
        cout << *v[i]; 
    }

    return 0;
}