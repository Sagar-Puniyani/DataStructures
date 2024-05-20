#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int signum(int a , int b ){
    if ( a == b ) 
        return 0;
    else if (a > b) 
        return 1;
    else 
        return -1;
}

void getMedian(int element, priority_queue<int> &maxHeap , priority_queue<int, vector<int>, greater<int>> &minHeap, int &median){
    switch (signum(maxHeap.size() , minHeap.size() ))
    {
    case 0:
        if (element > median){
            minHeap.push(element);
            median = minHeap.top();
        }
        else {
            maxHeap.push(element);
            median = maxHeap.top();
        }

        break;

    case 1:
        if( element > median ){
            minHeap.push(element);
            median = (maxHeap.top() + minHeap.top() ) / 2;
        }
        else{
            int temp = maxHeap.top();
            maxHeap.pop();
            minHeap.push(temp);
            maxHeap.push(element);
            median = (maxHeap.top() + minHeap.top() ) / 2;
        }
        break;


    case -1:
        if (element > median){
            maxHeap.push(minHeap.top());
            minHeap.pop();
            minHeap.push(element);
            median = (maxHeap.top() + minHeap.top() ) / 2;
        }
        else{
            maxHeap.push(element);
            median = (maxHeap.top() + minHeap.top() ) / 2;
        }
        break;
    
    default:
        break;
    }
}


vector<int> findMedian(vector<int> &arr, int n){
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;
    vector <int> ans;
    int median = 0;

    for (int i=0 ; i<n ; i++ ){
        getMedian(arr[i] , maxHeap , minHeap , median);
        ans.push_back(median);
    }
    return ans;

}

int main(){

    vector<int> arr = {5, 15, 10, 20, 3};
    int n = arr.size();
    vector<int> medians = findMedian(arr, n);

    for (int median : medians) {
        cout << median << " ";
    }
    cout << endl;


    return 0;
}