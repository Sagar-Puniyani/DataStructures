#include <iostream>
#include <stack>
using namespace std;


void print( stack <int> s ){
    if (s.empty() ) {
        cout << endl;
        return;
    }

    cout << s.top() << " ";
    s.pop();
    print(s);
}

void InsertSort(stack <int> &stack , int num  ){
    if ( stack.empty() || stack.top() <= num ) {
        stack.push(num);
        return;
    }

    else {
        int number = stack.top();
        stack.pop();
        InsertSort(stack , num );
        stack.push(number);
    }
}

void sortStack(stack<int> &stack){
    if ( stack.empty() ) {
        return;
    }

    int num = stack.top();
    stack.pop();
    sortStack(stack);
    InsertSort(stack , num);
}

int main()
{
    stack <int> s;
    s.push(23);
    s.push(5);
    s.push(63);
    s.push(0);
    print(s);
    sortStack(s);
    print(s);

    return 0;
}