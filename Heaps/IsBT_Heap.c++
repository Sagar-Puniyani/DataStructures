#include <iostream>
#include <queue>
using namespace std;


struct Node {
    int data;
    Node *left;
    Node *right;

Node(int val) {
    data = val;
    left = right = NULL;
}
};

bool isCBT(Node* root ){

    queue<Node*> q;
    q.push(root);

    bool flag = false;
    while (!q.empty() ) {

        Node* temp = q.front();
        q.pop();

        if (temp->left){
            if (flag) return false;
            q.push(temp->left);
        }else {
            flag = true;
        }
        
        if (temp->right){
            if (flag) return false;
            q.push(temp->right);
        }else {
            flag = true;
        }
    }

    return true;
}


bool ismaxHeap(Node* root){
    if (root->left == NULL && root->right == NULL ) 
        return true;
    
    if ( root->right == NULL )
        return root->data > root->left->data;

    else {
        return  root->data > root->left->data && 
                root->data > root->right->data && 
                ismaxHeap(root->left) && ismaxHeap(root->right);
    }
}


int countNode(Node* root){
    if (root == NULL ){
        return 0;
    }

    int leftCount = countNode(root->left);
    int rightCount = countNode(root->right);

    return leftCount + rightCount +1;
}

bool isHeap(struct Node* root) {
    return isCBT(root ) && ismaxHeap(root);
}


int main()
{
    Node* n1 = new Node(5);
    Node* n2 = new Node(3);
    Node* n3 = new Node(2);
    Node* n4 = new Node(2);


    n1->left = n2;

    n2->left = n3;
    n2->right = n4;
    
    cout << "Complte Binary Tree : " << isCBT(n1)<< endl;
    cout << "check Binary Tree is heap or not : " << isHeap(n1)<< endl;


    delete n1;
    delete n2;
    delete n3;
    delete n4;
    return 0;
}