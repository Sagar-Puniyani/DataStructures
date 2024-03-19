#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

bool isIdentical(Node *r1, Node *r2){
    // base case 
    if ( r1 == NULL && r2 == NULL ) return true;
    if ( r1 != NULL && r2 == NULL ) return false;
    if ( r1 == NULL && r2 != NULL ) return false;

    if ( r1->data != r2->data  ){
        return false;
    }
    else {
        bool leftIndentical = isIdentical( r1->left , r2->left);
        bool rightIndentical = isIdentical( r1->right , r2->right);

        return ( leftIndentical && rightIndentical);
    }
}

int main(){

    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(1);
    Node* n5 = new Node(2);
    Node* n6 = new Node(3);


    n1->left = n2;
    n1->right = n3;

    n4->left = n5;
    n4->right = n6;

    bool ans = isIdentical( n1 , n4 );
    cout << "Indentical : " << ans << endl;
    
    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;
    delete n6;

    return 0;
}