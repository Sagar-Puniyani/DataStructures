#include <iostream>
#include <stack>
using namespace std;

void print( stack <int> s ){
    if ( s.empty() ) {
        return ;
    }

    else{
        cout << " " << s.top();
        s.pop();
        print(s);
    }
    cout << endl;
}

class MinStack {
    stack <int> s;
        int min_;

public:
    MinStack() {
        min_ = INT_MAX;
    }
    
    void push(int curr) {
        
        if ( s.empty() ){
            s.push(curr);
            min_ = curr ;
        }
        else{
            if ( curr < min_ ){
                int value = (2 * curr) - min_ ;
                s.push(value);
                min_ = min(min_ , curr );
            }
            else{
                s.push(curr);
            }
        }
    }
    
    void pop() {
        if ( s.empty() ){
            return ;
        }
        int curr = s.top();

        if ( curr > min_){
            s.pop();
        }

        else{
            int value = ( 2 * min_ ) - (curr);
            min_ = value;
            s.pop();
        }
    }
    
    int top() {
        if (s.empty() ){
            return -1;
        }
        
        int curr = s.top();

        if ( curr < min_ ){
            return min_;
        }
        else{
            return curr;
        }
    }
    
    int getMin() {
        if (s.empty() ){
            return -1;
        }
        return min_;
    }
};

int main(){

    MinStack o;
    o.push(-3);
    cout << " min : " << o.getMin() << endl;
    o.push(0);
    cout << " min : " << o.getMin() << endl;
    o.push(-3);
    cout << " min : " << o.getMin() << endl;
    return 0;
}