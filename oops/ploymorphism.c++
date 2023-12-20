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
    void sayHello(){
        cout << "Helllo from Class B " << endl;
    }

};
int main()
{
    A obj;

    obj.sayHello();
    obj.sayHello("sagar");
    
    return 0;
}
