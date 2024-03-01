#include <iostream>
using namespace std;

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

        // Initilize top
        for ( int i=0 ; i<n ; i++ ){
            
        }
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // Write your code here.
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // Write your code here.
    }
};


int main()
{
    
    return 0;
}

