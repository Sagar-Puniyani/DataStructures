#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <chrono>
using namespace std;

void print ( vector <int>  arr ){
    for ( auto element :  arr ){
        cout << "  " << element ;
    }
    cout << endl;
}

int FindMaX( vector <int> &arr) {
    int max_ = INT_MIN;
    for ( int i=0 ; i<arr.size() ; i++ ){
        if (max_ < arr[i]){
            max_ = arr[i];
        } 
    }
    return max_;
}



int  FindSmaller(vector <int>  arr , stack <int> &s , int index){
    if (s.top() == arr.size() || s.top() < 0){
        return s.top();
    }
    if ( arr[s.top()] < arr[index]){
        return s.top();
    }

    else{
        s.pop();
        return FindSmaller(arr , s, index);
    }
}


vector<int> nextSmallerElements( vector<int> &arr ){
    vector<int> ans;
    stack <int> s;
    s.push(arr.size());
    for ( int i=arr.size()-1 ; i>=0 ; i--){
        int num = FindSmaller(arr, s , i);
        s.push(i);
        ans.insert(ans.begin() , num);
    }
    return ans;
}


vector <int> prevSmallerElement( vector<int> &arr){
    vector<int> ans;
    stack <int> s;
    s.push(-1);
    for ( int i=0 ; i<=arr.size()-1 ; i++ ){
        int num = FindSmaller(arr, s , i);
        s.push(i);
        ans.push_back(num);
    }
    return ans;
}


int largestRectangleArea(vector<int>& heights) {
    vector<int> left = prevSmallerElement(heights);
    vector<int> right = nextSmallerElements(heights);

    vector<int> Matrix;
    for ( int i=0 ; i<=heights.size()-1 ; i++ ){
        Matrix.push_back((right[i] - left[i] - 1) * heights[i]);
    }
    
    return FindMaX(Matrix);

}

int main()
{
    vector <int>  heights = {4 , 9 , 6 , 9};
    auto start = chrono::high_resolution_clock::now();
    int value = largestRectangleArea(heights);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << " largestRectangleArea  : " << value << endl;
    cout << "Execution time: " << duration.count() << " microseconds" << endl;
    return 0;
}