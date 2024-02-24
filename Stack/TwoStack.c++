#include <bits/stdc++.h> 
class TwoStack {
private:
    int top1;
    int top2;
    int *arr;
    int size;


public:

    // constructor 
    TwoStack(int s) {
        (*this).size = s;
        (*this).top1 = -1;
        (*this).top2 = s;
        (*this).arr = new int[s]; 
        
        }
    
    // Push in stack 1.
    void push1(int num) {
        if (top2 - top1 > 1){
            arr[++top1] = num;
        }
    }

    // Push in stack 2.
    void push2(int num) {
        if ( top2 - top1 > 1 ){
            arr[--top2 ] = num;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        if ( top1 > -1 ){
            int ans = arr[top1--];
            return ans;
        }
        else 
            return -1;
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        if ( top2 < size ){
            int ans = arr[top2++];
            return ans;
        }
        else
            return;
    }
};
