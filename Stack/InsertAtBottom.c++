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

stack<int> pushAtBottom(stack<int>& myStack, int x) {
    InsertAtBottom(myStack , x );
    return myStack;
}


int main()
{
    stack <int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    print(st);
    st =  pushAtBottom(st , 9);
    print(st);
    return 0;
}