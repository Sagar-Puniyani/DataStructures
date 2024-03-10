#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;


string FirstNonRepeating(string A) {
    unordered_map<char , int > count;
    queue <char> q;
    string ans = "";

    int len = A.length();

    for ( int i = 0 ; i<len ; i++ ){
        char ch = A[i];

        q.push(ch);
        count[ch]++;

        while  (! q.empty()){
            if( count[q.front()] > 1 ){
                q.pop();
            }
            else {
                ans.push_back(ch);
                break;
            }
        }
        if ( q.empty() ) {
            ans.push_back('#');
        }
        
    }
    return ans;
}



int main()
{
    string A = "abababaabac";
    cout << "A : " << A << endl;
    string ans = FirstNonRepeating(A);
    cout << "Ans : " << ans << endl;
    return 0;
}