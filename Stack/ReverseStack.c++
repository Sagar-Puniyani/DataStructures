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


void InsertAtBottom ( stack <int> & st , int x ){
    if ( st.empty() ) {
        st.push(x);
        return;
    }

    int num = st.top();
    st.pop();
    InsertAtBottom(st , x );
    st.push(num);
}




void reverseStack(stack<int> &stack) {
    if ( stack.empty() ) {
        return;
    }

    int num = stack.top();
    stack.pop();
    reverseStack(stack);
    InsertAtBottom(stack , num );
}


int main()
{
    stack<int> s;
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    print(s);
    reverseStack(s);
    print(s);
    return 0;
}