#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x) : data(x) , left(NULL) , right(NULL){}
};



Node* lca(Node* root, int n1, int n2) {
    if (root == NULL) return nullptr;
    else if (root->data == n1 || root->data == n2) {
        cout << "Data : " << root->data << endl;
        return root;
    }

    Node* Left = lca(root->left, n1, n2);
    Node* Right = lca(root->right, n1, n2);

    if (Left != NULL && Right == NULL) {
        return Left;
    }
    else if (Left == NULL && Right != NULL) {
        return Right;
    }
    else if (Left != NULL && Right != NULL) {
        return root;
    }
    else
        return nullptr;
}



void Inorder( Node* root ){
    if ( root == NULL ){
        return;
    }

    Inorder(root->left);
    cout <<"  " <<  root->data ;
    Inorder(root->right);
}


int main()
{

    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(6);
    Node* n5 = new Node(4);
    Node* n6 = new Node(5);
    Node* n7 = new Node(8);
    Node* n8 = new Node(21);
    
    
    n1->left = n2;
    n1->right = n3;

    n2->left = n4;

    n3->left = n5;
    n3->right = n6;
    
    n4->right = n7;

    n6->left = n8;


    Node* n = lca( n1 , 21 , 4 );
    cout << "LCA : " << n->data << endl;

    Inorder(n1);
    
    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;
    delete n6;
    delete n7;
    delete n8;


    return 0;
}