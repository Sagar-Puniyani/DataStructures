#include <iostream>
#include <stack>
using namespace std;

bool IsMatch(stack<char> &st, char closingBracket) {
    char openingBracket;
    switch (closingBracket) {
        case ')': openingBracket = '('; break;
        case ']': openingBracket = '['; break;
        case '}': openingBracket = '{'; break;
        default: return false;
    }

    bool hasOperator = false;
    while (!st.empty() && st.top() != openingBracket) {
        char top = st.top();
        if (top == '+' || top == '-' || top == '*' || top == '/') {
            hasOperator = true;
        }
        st.pop();
    }

    if (!st.empty() && st.top() == openingBracket) {
        st.pop();
    }

    return !hasOperator;
}

bool CheckRedundant(stack<char> &st, string s, int index) {
    if (index >= s.length()) {
        return false;
    }

    if (s[index] == '(' || s[index] == '[' || s[index] == '{' ||
        s[index] == '+' || s[index] == '-' || s[index] == '*' || s[index] == '/') {
        st.push(s[index]);
    } else if (s[index] == ')' || s[index] == ']' || s[index] == '}') {
        if (IsMatch(st, s[index])) {
            return true;
        }
    }

    return CheckRedundant(st, s, index + 1);
}

bool findRedundantBrackets(string &s) {
    stack<char> st;
    return CheckRedundant(st, s, 0);
}

int main() {
    string s = "(a+b-c)";
    cout << "Is Redundant Bracket : " << findRedundantBrackets(s) << endl;
    return 0;
}