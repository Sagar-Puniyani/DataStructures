#include <iostream>
using namespace std;


class A {
    private: 
    int x = 10 ;
    string name = "classA";


    public:
    A(){
        cout << "Contructor Called " << endl;
    }

    void SayHello(){
        cout << "Hello " << endl;
    }

    void SaySomething(){
        cout << "Something is good from A  " << endl;
    }
};



class B {
    private:
        int y = 20;
        string name = "classB";


    public:

    void SaySomething(){
        cout << "Something is good from B " << endl;
    }
};
// multiple inheritance 
class C : public A , public B {
    public : 
    void call() {
        cout << "Calling " << endl;
    }

};

int main()
{
    C obj;

    obj.call();
    obj.SayHello();
    obj.A::SaySomething();
    obj.B::SaySomething();


    // inheritance Ambiguity 

    
    return 0;
}
