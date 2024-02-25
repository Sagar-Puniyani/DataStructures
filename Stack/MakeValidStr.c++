#include <iostream>
#include <stack>
using namespace std;

int findMinimumCost(string str) {
    if ( str.length()%2 != 0 ){
        return -1;
    } 

    stack <char> s;
    for ( int i=0 ; i<str.length() ; i++){
        if ( str[i] == '{'){
            s.push(str[i]);
        }
        else {
            if ( !s.empty() && s.top() == '{'){
                s.pop();
            }
            else{
                s.push(str[i]);
            }
        }
    }

    int a = 0 , b = 0;
    while(!s.empty() ){
        if (s.top() == '{')
            a++;
        else
            b++;
        s.pop();
    }

    return (a+1)/2 + (b+1)/2;

}

int main()
{
    string s = "{{{{";
    int ans = findMinimumCost(s);
    cout << "Minimum Cost is : " << ans << endl;
    return 0;
}