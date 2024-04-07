#include <iostream>
#include <queue>
#include <map>
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

void MorrisTraversal ( Node * root ){
    if ( root == NULL ) return;

    Node* curr = root;

    while ( curr != NULL ){
        if ( curr->left == NULL ){
            cout << " " << curr->data ;
            curr = curr->right;
        }
        else {
            Node* pred = FindPred(curr);
            if ( pred->right == NULL ){
                pred->right = curr;
                curr = curr->left;
            }
            else {
                pred->right == nullptr;
                cout << " " << curr->data;
                curr = curr->right;
            }
        }
    }
}


void Inorder( Node* root ){
    if ( root == NULL ){
        return;
    }

    Inorder(root->left);
    cout <<"  " <<  root->data ;
    Inorder(root->right);
}

int main(){

    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n6 = new Node(6);
    Node* n7 = new Node(7);
    
    
    n1->left = n2;
    n1->right = n3;

    n2->left = n4;

    n3->right = n6;

    n4->right = n7;

    cout << "Inorder Traversal : " << endl;
    Inorder(n1);
    cout << endl;


    cout << "Morris Traversal : " << endl;
    MorrisTraversal(n1);
    cout << endl;



    
    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n6;
    delete n7;

    return 0;
}