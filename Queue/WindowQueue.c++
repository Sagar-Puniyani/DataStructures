#include <iostream>
#include <deque>
#include <vector>
using namespace std;
template <typename T > 

vector<long long> printFirstNegativeInteger(T *A,
                                                long long int N, long long int K) {
    
    deque <long long int> dq;
    vector <long long > ans;

    for ( int i=0 ; i<K ; i++){
        if ( A[i] < 0 ){
            ans.push_back(A[i]);
        }
    }
    


    // process for remaining windows 
    for ( int i=K ; i<N ; i++ ){

        if ( dq.size() > 0 ){
        ans.push_back(A[dq.front()]);
        }
        else {
            ans.push_back(0);
        }
        // removal 
        if (!dq.empty() &&  i - K >= dq.front()){
            dq.pop_front();
        }
        
        if ( A[i] < 0 ){
            dq.push_back(A[dq.front()]);
        }

    }
    return ans;
}

template <typename T > 
void print ( vector <T>  arr){
    cout << "Called" << endl;
    for ( auto element : arr ) {
        cout << " " << element << endl;
    }
    cout << endl;
}



// Driver program to test above functions
int main() {
    long long int N = 8;
    long long int A[] = {12, -1, -7, 8, -15, 30, 16, 28};
    long long int K = 3;
    vector < long long > ans = printFirstNegativeInteger(A , N , K  );
    print(ans);
}

