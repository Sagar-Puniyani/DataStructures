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


int height(struct Node* node){

    if ( node == NULL){
        return 0;
    }
    else {
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        return max(leftHeight , rightHeight ) + 1;
    }
}


int main()
{
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    n1->left = n2;
    n2->left = n3;
    n3->left = n4;

    int ans = height(n1);
    cout << "Height : " << ans << endl;


    delete n1;
    delete n2;
    delete n3;
    delete n4;


    return 0;
}