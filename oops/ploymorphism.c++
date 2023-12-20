#include <iostream>
using namespace std;

class A{
    public:

    // function OverLoading 
    void sayHello(){
        cout << "Helllo from Class A " << endl;
    }

    void sayHello(string str ){
        cout << "Helllo from Class A " << str  << endl;
    }


};

class B {
    public:
    int a;
    int b;


    int add(){
        return a+b;
    }

    void operator+ (B object ){
        int v1 = (*this).a;
        int v2 = object.a;
        cout << "Output = " << v2-v1 << endl;
        cout << "Subtraction is done "<< endl;
    }

};
int main()
{
    A obj;

    obj.sayHello();
    obj.sayHello("sagar");

    B obj1 , obj2 ;
    obj1.a = 7;
    obj2.a = 17;

    obj1 + obj2;
    
    return 0;
}
