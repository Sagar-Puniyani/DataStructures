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
};



class B {
    private:
        int y = 20;
        string name = "classB";


    public:

    void SaySomething(){
        cout << "Something is good " << endl;
    }
};

class C : public A , public B {
    public : 

};

int main()
{
    
    return 0;
}
