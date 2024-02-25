#include <iostream>
#include <stack>
#include <vector> 
using namespace std;

void print ( vector <int>  arr ){
    for ( auto element :  arr ){
        cout << "  " << element ;
    }
    cout << endl;
}

int FindSmaller(stack <int>& s , int num){
    if (  s.top() < num ){
        return s.top();
    }
    else {
        s.pop();
        return FindSmaller(s , num );
    }
}

vector<int> nextSmallerElement(vector<int> &arr, int n){   
    
    vector <int> ans(n);
    stack <int> s;
    s.push(-1);
    for ( int i=n-1 ; i>=0 ; i--){
        int num = FindSmaller( s , arr[i]);
        s.push(arr[i]);
        ans.insert(ans.begin() , num);
    }

    return ans;
}


int main()
{
    vector <int> arr = {2 , 1 , 4 , 3 };
    print(arr);
    vector <int>  ans = nextSmallerElement(arr , 4 );
    print(ans);
    return 0;
}