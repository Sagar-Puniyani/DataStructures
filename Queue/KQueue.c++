#include <iostream>
using namespace std;


class KQueue {

    public:
    int n;
    int k;
    int* arr;
    int* front;
    int* rear;
    int* next;
    int freespot;

    KQueue( int n , int k ){
        (*this).n = n;
        (*this).k = k;

        front = new int[k];
        rear = new int[k];
        for ( int i=0 ; i<k ; i++){
            front[i] = -1;
            rear[i] = -1;
        }

        next = new int[n];
        for ( int i=0 ; i<n ; i++ ){
            next[i] = i+1;
        }
        next[n-1] = -1;

        freespot = 0;
    }

    void enqueue ( int data , int qn ){
        // overflow 
        if ( freespot == -1 ){
            cout << " Overflow " << endl;
            return;
        }

        // find freespot 
        int index = freespot;

        // update freespot 
        freespot = next[index];

        // check first insert 
        if ( front[qn-1] == -1 ){
            
        }
    }
};


int main()
{
    
    return 0;
}