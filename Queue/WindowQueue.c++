#include <iostream>
#include <deque>
#include <vector>
using namespace std;
template <typename Container>
void print(const Container& container) {
    std::cout << "[ ";
    for (const auto& element : container) {
        std::cout << element << " ";
    }
    std::cout << "]\n";
}

vector<long long> printFirstNegativeInteger(long long int A[],
                                                long long int N, long long int K) {
    
    cout << "Printing " << endl;
    deque <long long int> dq;
    vector <long long > ans;

    for ( int i=0 ; i<K ; i++){
        if ( A[i] < 0 ){
            dq.push_back(i);
        }
    }
    print(dq);

    if ( dq.size() > 0 ){
        ans.push_back(A[dq.front()]);
    }
    else {
        ans.push_back(0);
    }


    // process for remaining windows 
    for ( int i=K ; i<N ; i++ ){

        // removal 
        if (!dq.empty() &&  i - dq.front()>= K ){
            dq.pop_front();
        }
        // Addition 
        if ( A[i] < 0 ){
            dq.push_back(i);
        }

//      ans store 
        if ( dq.size() > 0 ){
        ans.push_back(A[dq.front()]);
        }
        else {
            ans.push_back(0);
        }
    }
    return ans;
}



// Driver program to test above functions
int main() {
    long long int N = 8;
    long long int A[] = {12, -1, -7, 8, -15, 30, 16, 28};
    long long int K = 3;
    vector < long long > ans = printFirstNegativeInteger(A , N , K  );
    print(ans);
    return 0;
}

