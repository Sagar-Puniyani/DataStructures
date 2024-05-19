#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int getKthLargest(vector<int> &arr, int k){

    vector <int> sumStore;

    for (int i=0 ; i<arr.size() ; i++){

        int sum=0;
        for ( int j=i ; j<arr.size() ; j++){
            sum += arr[j];
            sumStore.push_back(sum);
        }
    }

    sort(sumStore.begin() , sumStore.end() );
    cout << sumStore.size() << endl;

    return sumStore[sumStore.size() - k];

}


int getKthLargestUsingHeap(vector<int> &arr, int k){

    priority_queue< int, vector<int>, greater<int> > pq;
    for (int i=0 ; i<arr.size() ; i++){

        int sum=0;
        for ( int j=i ; j<arr.size() ; j++){
            sum += arr[j];

            if ( pq.size() < k){
                pq.push(sum);
            }
            else {
                if (pq.top() < sum ){
                    pq.pop();
                    pq.push(sum);
                }
            }
        } 
    }

    cout << pq.size() << endl;

    return pq.top();

}


int main(){

    vector <int> arr = {1, -2, 3, -4, 5};
    int ans = getKthLargest(arr , 2);
    cout << "K th Largest Sum : " << ans << endl;

    ans = getKthLargestUsingHeap(arr , 2);
    cout << "K th Largest Sum : " << ans << endl;
    return 0;
}