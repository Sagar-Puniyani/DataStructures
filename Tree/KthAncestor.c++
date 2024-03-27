#include <iostream>
#include <vector>
using namespace std;


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x) : data(x) , left(NULL) , right(NULL){}
};

Node* solution(Node* root , int &k , int node ){
    // base case 
    if ( root == NULL ) return nullptr;

    else if( root->data == node )  return root;

    else {
        Node * Left = solution(root->left , k , node );
        Node * Right = solution(root->right , k , node );

        if ( Left != NULL && Right  == NULL ){
            k--;
            if ( k==0 ){
                k = INT_MAX;
                return root;
            }
            return Left;
        }
        if ( Left == NULL && Right  != NULL ){
            k--;
            if ( k==0 ){
                k = INT_MAX;
                return root;
            }
            return Right;
        }
        return nullptr;
    }
}


int kthAncestor(Node *root, int k, int node){
    Node* ans = solution(root , k , node );
    if ( ans == NULL || root->data == node)
        return -1;
    else 
        return ans->data;
}


int  main(){
    Node* n1 = new Node(1);
    Node* n2 = new Node(3);
    Node* n3 = new Node(-1);
    Node* n4 = new Node(2);
    Node* n5 = new Node(1);
    Node* n6 = new Node(4);
    Node* n7 = new Node(5);
    Node* n8 = new Node(1);
    Node* n9 = new Node(1);
    Node* n10 = new Node(2);
    Node* n11 = new Node(6);
    
    
    n1->left = n2;
    n1->right = n3;

    n2->left = n4;
    n2->right = n5;

    n3->left = n6;
    n3->right = n7;

    n5->left = n8;

    n6->left = n9;
    n6->right = n10;

    n7->right = n11;

    int ans = sumK(n1 , 5 );
    cout << "Ans : " << ans << endl;

    
    
    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;
    delete n6;
    delete n7;
    delete n8;
    delete n9;
    delete n10;
    delete n11;
    
    return 0;
}