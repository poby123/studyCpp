#include<iostream>
#include<functional>
using namespace std;

// function
void printHello(void){
    cout << "Hello!" << endl;
}


// struct function
struct S {
    void operator()(void) { 
      cout << "This is S " << endl; 
    }
};

// class member function
class Student{
    string name;

public:
    Student(string name):name(name){}

    string getName(void){
        return name;
    }

    void setName(string name){
        this->name = name;
    }

    void print(){
        cout << name << endl;
    }
};

int main(){

    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int len = sizeof(arr)/sizeof(int);

    /* lambda */
    function<void(void)> l1 = [](){cout << "This is lambda" << endl;};
    l1();

    function<void(int*, int)> l2 = [](int* arr, int len){for(int i=0;i<len;i++){arr[i]*=2; cout << arr[i] << " ";}};
    l2(arr, 10);
    cout << endl;

    function<void()> l3 = [=, &arr](){for(int i=0;i<len;i++){arr[i]*=2; cout << arr[i] << " ";}};
    l3();
    cout << endl;

    /* general function */
    function<void(void)> pH = printHello;
    pH();

    /* struct function */
    function<void(void)> ps = S();
    ps();

    /* class function */
    Student s("Watt");
    function<void(Student&, string)> sSetname = &Student::setName;
    sSetname(s, "Amy");

    function<string(Student&)> sGetname = &Student::getName;
    cout << sGetname(s) << endl; 

    return 0;
}