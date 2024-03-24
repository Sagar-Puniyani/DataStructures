#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x) : data(x) , left(NULL) , right(NULL){}
};


vector<int> topView(Node *root){
    map<int, int> m;
queue<pair<int, Node*>> q;
vector<int> ans;

// critical case 
if (root == NULL) {
    return ans;
}

q.push(make_pair(0, root));

while (!q.empty()) {
    pair<int, Node*> temp = q.front();
    q.pop();
    int row = temp.first;
    Node* frontNode = temp.second;

    // Insert into map only if the key doesn't exist
    if (m.find(row) == m.end()) {
        m[row] = frontNode->data;
    }

    if (frontNode->left) {
        q.push(make_pair(row - 1, frontNode->left)); // Using frontNode instead of root
    }
    if (frontNode->right) {
        q.push(make_pair(row + 1, frontNode->right)); // Using frontNode instead of root
    }
}

    // Copy elements from map to ans
    for (auto item : m) {
        ans.push_back(item.second);
    }

    return ans;

}

void main(){
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    Node* n7 = new Node(7);
    
    
    

    
    
    
    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;
    delete n6;
    delete n7;
    
    return ;
}