#include <iostream>
#include <stack>
using namespace std;


bool ValidParentheis( string s , stack<char> & st , int index , int size ){
    if ( index >= size  ) return st.empty();

    if ( s[index] == '[' || s[index] == '{' || s[index] == '('){
        st.push(s[index]);
    }
    else if ( !st.empty() ){
        if (   (st.top() == '[' && s[index] == ']') || 
                (st.top() == '(' && s[index] == ')') ||   
                (st.top() == '{' && s[index] == '}'))
        {
            st.pop();
        }
        else {
            return false;
        }
    }

    else 
        return false;


    return ValidParentheis(s , st ,  index +1 , size );
}

bool isValid(string s) {
    stack <char> st;
    return ValidParentheis(s , st , 0 , s.length());
}


int main()
{
    string s = "(])";
    cout << "Is Valid Parentheis : " << isValid(s);
    return 0;
}