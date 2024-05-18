#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node { 
    public: 
    int data; 
    Node *left; 
    Node *right; 
    
    Node(int d) { 
        data = d; 
        left = right = NULL; 
    } 
};

void levelOrder(Node *root) {
    if (root == NULL) {
        return;
    }
    
    queue<Node*> q;
    q.push(root);
    
    while (!q.empty()) {
        Node *curr = q.front();
        q.pop();
        
        cout<<curr->data<<" ";
        
        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL) 
            q.push(curr->right);
    }
}

void storeInorder(Node *root , vector<int>& arr){
    if (root == NULL ) return;

    storeInorder(root->left , arr);
    arr.push_back(root->data);
    storeInorder(root->right , arr);
}

void placePreOrder(Node* root , vector<int> &arr){
    if (root == NULL ) return;

    root->data = arr[0];
    arr.erase(arr.begin());
    placePreOrder(root->left , arr);
    placePreOrder(root->right , arr);
}

void convertToMinHeap(Node *root) {

    vector<int> inorder;

    storeInorder(root , inorder);

    placePreOrder(root , inorder);

}

int main()
{
    Node* n1  = new Node(12);
    Node* n2  = new Node(7);
    Node* n3  = new Node(18);
    Node* n4  = new Node(6);
    Node* n5  = new Node(9);
    Node* n6  = new Node(13);
    Node* n7  = new Node(23);


    n1->left = n2;
    n1->right = n3;

    n2->left = n4;
    n2->right = n5;

    n3->left = n6;
    n3->right = n7;

    cout << "Before : " << endl;
    levelOrder(n1);
    cout<<endl;

    convertToMinHeap(n1);

    cout << "After : " << endl;
    levelOrder(n1);
    cout<<endl;

    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;
    delete n6;
    delete n7;
    
    return 0;
}