#include <iostream>
using namespace std;


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x) : data(x) , left(NULL) , right(NULL){}
};

Node* FindPred(Node* node ){
    if ( node == NULL ) return nullptr;

    Node *pred = node ->left;
    while ( pred->right != NULL && pred->right != node ){
        pred = pred ->right;
    }
    // cout << "Pred : " << pred->data << endl;
    return pred;
}


void Inorder( Node* root ){
    if ( root == NULL ){
        return;
    }

    Inorder(root->left);
    cout <<"  " <<  root->data ;
    Inorder(root->right);
}

void flatten(Node *root){
    if ( root == NULL ) return;

    Node* curr = root;

    while( curr != NULL ){
        if ( curr->left == NULL ){
            curr = curr->right;
        }
        else {
            Node* pred = FindPred(curr);
            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = nullptr;
        }
    }
}

void print( Node* head ){
    if ( head == NULL) return;

    while (head != NULL ) {
        cout << " " << head->data;
        head = head->right;
    }
    cout << endl;
}


int main(){

    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    
    
    n1->left = n2;
    n1->right = n5;

    n2->left = n3;
    n2->right = n4;

    n5->right = n6;

    cout << "Inorder Traversal : " << endl;
    Inorder(n1);
    cout << endl;

    cout << "Flatten a Tree : " << endl;
    flatten(n1);
    print(n1);



    
    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;
    delete n6;

    return 0;
}