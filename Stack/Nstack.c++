#include <iostream>
using namespace std;

void print(int *arr , int n ) {
    for ( int i=0 ; i<n ; i++){
        cout << "  " << arr[i];
    }
    cout << endl;
} 

class NStack
{

public:
    int *arr;
    int *next;
    int *top;

    int n , s;
    int freespot;

public:

    NStack(int N, int S)
    {
        n = N;
        s = S;

        arr = new int[s];
        top = new int[n];
        next = new int[n];

        for ( int i=0 ; i<n ; i++ ) {
            top[i] = -1;
        }

        for ( int i=0 ; i<s ; i++) {
            next[i] = i+1;
        }
        next[s-1] = -1;

        freespot = 0;
    }


    bool push(int x, int m)
    {
        if ( freespot == -1 ){
            cout << "stack underflow " << endl;
            return false;
        }

        // 1. find index 
        int index = freespot;

        // 2. update freespot 
        freespot = next[index];

        // 3. insert in array 
        arr[index] = x;

        // 4. update next 
        next[index] = top[m-1];

        // 5. update top
        top[m-1] = index;

        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // underflow
        if ( top[m-1] == -1 ){
            return -1;
        }

        int index = top[m-1];

        top[m-1] = next[index];

        next[index] = freespot;

        freespot = index;

        return arr[index];
    }


};


int main()
{
    NStack obj = NStack(3 , 9);

    obj.push( 10 , 1);
    cout << "arr" ;
    print(obj.arr , obj.s);
    cout << "next" ;
    print(obj.next , obj.s);
    cout << "top" ;
    print(obj.top , obj.n);
    cout << "freespot " << obj.freespot <<  endl;
    cout<< endl;


    obj.push( 1000 , 2);
    cout << "arr" ;
    print(obj.arr , obj.s);
    cout << "next" ;
    print(obj.next , obj.s);
    cout << "top" ;
    print(obj.top , obj.n);
    cout << "freespot " << obj.freespot << endl;
    cout<< endl;

    obj.push( 9 , 3);
    cout << "arr" ;
    print(obj.arr , obj.s);
    cout << "next" ;
    print(obj.next , obj.s);
    cout << "top" ;
    print(obj.top , obj.n);
    cout << "freespot " << obj.freespot << endl;
    cout<< endl;


    obj.push( 20 , 1);
    cout << "arr" ;
    print(obj.arr , obj.s);
    cout << "next" ;
    print(obj.next , obj.s);
    cout << "top" ;
    print(obj.top , obj.n);
    cout << "freespot " << obj.freespot << endl;
    cout<< endl;

    obj.push( 30 , 1);
    cout << "arr" ;
    print(obj.arr , obj.s);
    cout << "next" ;
    print(obj.next , obj.s);
    cout << "top" ;
    print(obj.top , obj.n);
    cout << "freespot " << obj.freespot << endl;
    cout<< endl;

    obj.push( 2000 , 2);
    cout << "arr" ;
    print(obj.arr , obj.s);
    cout << "next" ;
    print(obj.next , obj.s);
    cout << "top" ;
    print(obj.top , obj.n);
    cout << "freespot " << obj.freespot << endl;
    cout<< endl;

    obj.push( 19 , 3 );
    cout << "arr" ;
    print(obj.arr , obj.s);
    cout << "next" ;
    print(obj.next , obj.s);
    cout << "top" ;
    print(obj.top , obj.n);
    cout << "freespot " << obj.freespot << endl;
    cout<< endl;


    obj.push( 3000 , 2);
    cout << "arr" ;
    print(obj.arr , obj.s);
    cout << "next" ;
    print(obj.next , obj.s);
    cout << "top" ;
    print(obj.top , obj.n);
    cout << "freespot " << obj.freespot << endl;
    cout<< endl;

    obj.push( 40 , 1);
    cout << "arr" ;
    print(obj.arr , obj.s);
    cout << "next" ;
    print(obj.next , obj.s);
    cout << "top" ;
    print(obj.top , obj.n);
    cout << "freespot " << obj.freespot << endl;
    cout<< endl;
    cout<< endl;


    int var = obj.pop(1);
    cout << "var  " << var << endl;
    cout << "arr" ;
    print(obj.arr , obj.s);
    cout << "next" ;
    print(obj.next , obj.s);
    cout << "top" ;
    print(obj.top , obj.n);
    cout << "freespot " << obj.freespot << endl;
    cout<< endl;

    var = obj.pop(1);
    cout << "var  " << var << endl;
    cout << "arr" ;
    print(obj.arr , obj.s);
    cout << "next" ;
    print(obj.next , obj.s);
    cout << "top" ;
    print(obj.top , obj.n);
    cout << "freespot " << obj.freespot << endl;
    cout<< endl;

    var = obj.pop(1);
    cout << "var  " << var << endl;
    cout << "arr" ;
    print(obj.arr , obj.s);
    cout << "next" ;
    print(obj.next , obj.s);
    cout << "top" ;
    print(obj.top , obj.n);
    cout << "freespot " << obj.freespot << endl;
    cout<< endl;

    var = obj.pop(1);
    cout << "var  " << var << endl;
    cout << "arr" ;
    print(obj.arr , obj.s);
    cout << "next" ;
    print(obj.next , obj.s);
    cout << "top" ;
    print(obj.top , obj.n);
    cout << "freespot " << obj.freespot << endl;
    cout<< endl;



    return 0;
}

