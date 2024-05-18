#include <iostream>
#include <queue>
using namespace std;

long long int minCost(long long int arr[], long long int n) {
    priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
    
    for ( int i=0 ; i<n ; i++ ){
        pq.push(arr[i]);
    }

    long long int ans = 0;
    while(pq.size() > 1){
        long long int a = pq.top();
        pq.pop();

        long long int b = pq.top();
        pq.pop();

        long long int sum = a+b;
        ans += sum;

        pq.push(sum);
        n--;
    }

    return ans;
}

int main()
{
    long long int arr[] = {4,3,2,6};
    long long int size = sizeof(arr)/sizeof(arr[0]);
    long long int ans = minCost(arr,size);
    cout << "Min Cost of Rope : " << ans << endl;

    return 0;
}