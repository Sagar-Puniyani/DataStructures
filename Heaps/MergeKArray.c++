#include <iostream>
#include <queue>
#include <vector>
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

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k){
    // STEP 1: place all first element in heap
    priority_queue< Node* , vector<Node*> , compare> pq;

    for ( int i=0 ; i<k ; i++){
        if (!kArrays[i].empty()) {
            Node* newNode = new Node(kArrays[i][0], i , 0);
            pq.push(newNode);
        }
    }

    cout << "size : " << pq.size() << endl;

    vector<int> ans;
    while (!pq.empty() ){
        Node* node = pq.top();
        pq.pop();

        ans.push_back(node->data);

        int column = node->col + 1;
        int noRow = node->row;
        if ( column < kArrays[noRow].size()){
            Node * temp = new Node(kArrays[noRow][column], noRow, column);
            pq.push(temp);
        }

        delete node;
    }
    
    return ans;
}

int main()
{
    vector<vector<int>> kArrays = {
        {12 , 24},
        {5, 11, 19 , 50 },
        {2, 6, 12 , 100},
        {27}
    };

    int k = kArrays.size();
    cout << "size = " << k << endl; 
    vector<int> result = mergeKSortedArrays(kArrays, k);

    cout << "Merge of k sorted Arrays : " << endl;
    for (int val : result) {
        cout << val << " ";
    }


    return 0;
}