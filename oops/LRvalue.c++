#include <iostream>
using namespace std;


int& GetValue(){
    static int value = 10;
    cout << "value  = " << value << endl;
    return value;
}

void PrintName( const string & name ){
    cout << "Name : l -- " << name << endl;
}

void PrintName( const string && name ){
    cout << "Name : r -- " << name << endl;
}

int main(){
    /*
    int a = 10;

    cout << "&a = " << &a << endl;

    static int value = 10;

    cout << "value = " <<  value << endl;

    GetValue() = 909;
    int i = GetValue();
    cout << "i = " << i << endl;
    */


    string firstName = "sagar";
    string LastName = "puniyani";

    string fullname = firstName + LastName;



    PrintName(fullname);
    PrintName(firstName + LastName);

    return 0;
}