#include <iostream>
#include <vector>
using namespace std;

void printArr(vector<int> arr){
    for ( int element : arr ){
        cout << " " << element;
    }
    cout << endl;
}

// To print all the sub sequences 
void subseq(int index, int n , vector<int> arr, vector<int> &ans){
    if (index >= n ){
        printArr(ans);
        return;
    }

    ans.push_back(arr[index]);
    subseq(index+1, n, arr, ans);

    ans.pop_back();
    subseq(index+1, n, arr, ans);
}



int main(){
    vector <int> arr = {4,5,7,9,6,2,1,0,3,8};
    vector <int> ans = {};

    subseq(0, 10, arr, ans);

    return 0;
}