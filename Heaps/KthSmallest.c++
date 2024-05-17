#include <iostream>
#include <queue>
using namespace std;

int kthSmallest(int arr[], int l, int r, int k){
    priority_queue<int>  h;
    for ( int i=l ; i<k ; i++ ){
        h.push(arr[i]);
    }

    for ( int i=k ; i<=r ; i++ ){
        if (h.top() > arr[i]){
            h.pop();
            h.push(arr[i]);
        }
    }

    return h.top();
}


int main(){

    int arr[] = {7,10,4,3,20,15};
    int ans = kthSmallest(arr , 0 , 5 , 3 );
    cout << " Kth Smallest Element : " << ans << endl;
    return 0;
}