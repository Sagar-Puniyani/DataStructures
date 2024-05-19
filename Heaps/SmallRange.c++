#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

class Node{

public:
    int data;
    int row;
    int col;

    Node(int data ,int row ,int col ){
        (*this).data = data;
        this->row = row;
        this->col = col;
    }

};

struct compare {
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};


int kSorted(vector<vector<int>> &a, int k, int n) {

    priority_queue< Node* , vector<Node*> , compare> pq;
    int start = INT_MAX;
    int end = INT_MIN;
    for (int i=0 ; i<k ; i++ ){
        int element = a[i][0];
        start = min(element , start );
        end = max(element , end);
        pq.push(new Node(element, i , 0));
    }

    cout << "start : " << start << endl;
    cout << "end : " << end << endl;

    // traverse remaining range
    int mini = start , maxi = end;
    while ( !pq.empty() ){
        Node* top = pq.top();
        pq.pop();

        start = top->data;
        cout << "starting = " << start << endl;

        if ( maxi-mini > end-start ){
            cout << "change : " << endl;
            cout << "(mini, maxi): (" << mini << ", " << maxi << ") ";
            cout << "(start, end): (" << start << ", " << end << ")" << endl;
            mini = start;
            maxi = end;
        }

        int nextCol = top->col +1;
        if ( nextCol < a[top->row].size() ){
            end = max(end , a[top->row][nextCol]);
            pq.push(new Node(a[top->row][nextCol], top->row, nextCol));
        }else {
            break;
        }
    }
    

    return ( maxi - mini + 1);

}

int main(){
    vector<vector<int>> arrays = {
        {1,10,11},
        {2,3,20},
        {5,6,12}
    };
    int k = arrays.size();
    int n = 0; 

    int result = kSorted(arrays, k, n);
    cout << "The smallest range is: " << result << endl; // Expected output: 6 (from range [20, 24])

    return 0;
    return 0;
}