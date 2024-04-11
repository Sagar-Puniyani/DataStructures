#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x) : data(x) , left(NULL) , right(NULL){}
};

Node* searchBST(Node* root, int val) {
    // base case 
    if ( root == NULL ) return nullptr;
    if ( (*root).data == val ){
        return root;
    }

    if ( (*root).data > val ){
        return searchBST( root->left , val);
    }
    else {
        return searchBST( root->right , val);
    }
}

Node* MinValue( Node* root){
    if (root == NULL ) return nullptr;

    while( root->left != NULL ){
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int key) {
    // base case 
    if ( root == NULL ) return root;


    if ( root->data == key ){
        if ( root->left == NULL && root->right == NULL ){
            delete root;
            return nullptr;
        }

        if ( root->left != NULL && root->right == NULL ){
            Node* LeftNode = root->left;
            delete root;
            return LeftNode;
        }

        if ( root->left == NULL && root->right != NULL ){
            Node* RightNode = root->right;
            delete root;
            return RightNode;
        }

        if ( root->left != NULL && root->right != NULL ){
            int mini = MinValue(root->right) ->data;
            root->data = mini;
            root->right = deleteNode( root->right , mini );
            return root;
        }
    }
    else if ( root->data > key ){
        root->left   = deleteNode( root->left , key);
    }
    else {
        root->right =  deleteNode( root->right , key);
    }

    return root;
}

void Inorder ( Node* root ){
    if ( root == NULL ) return;

    Inorder(root->left);
    cout << "  " << root->data ;
    Inorder( root->right);
}


int main(){
    Node* n1 = new Node(5);
    Node* n2 = new Node(3);
    Node* n3 = new Node(6);
    Node* n4 = new Node(2);
    Node* n5 = new Node(4);
    Node* n6 = new Node(7);
    
    
    n1->left = n2;
    n1->right = n3;

    n2->left = n4;
    n2->right = n5;

    n3->right = n6;

    cout << "Tree is : " << endl;
    Inorder(n1);


    Node* NewNode = searchBST(n1 , 2);
    cout << endl;
    cout << "New Node Tree : " << endl;
    Inorder(NewNode);

    Node* root = deleteNode(n1 , 4); 
    cout << endl;
    cout << "Tree After Delete the Node is : " << endl;
    Inorder(n1);   
    
    
    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;

    return 0;
}