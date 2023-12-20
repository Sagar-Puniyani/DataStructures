#include <iostream>
#include <vector>
using namespace std;

class A{
    private:
        int c =  48767;

    public:

    void printc(){
        cout << c << endl;
        cout << this->c << endl;

    }

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

    void operator+ (B &object ){
        int v1 = (*this).a;
        int v2 = object.a;
        cout << "Output = " << v2-v1 << endl;
        cout << "Subtraction is done "<< endl;
    }


};
class C : public B {
    public:
    void operator + (B &object ){
        int v1 = (*this).a;
        int v2 = object.a;
        cout << "Output = " << v1*v2 << endl;
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

    C obj3 , obj4 ;
    obj3.a = 7;
    obj4.a = 17;
    obj3 + obj4 ;


    obj.printc();
    
    return 0;
}
