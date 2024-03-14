#include <iostream>
using namespace std;


template <typename T>
    class BinaryTreeNode {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
        }
};



int noOfLeafNodes(BinaryTreeNode<int> *root){
    if ( root == NULL ) return 0;
    if ( root->left == NULL && root->right == NULL){
        return 1;
    }

    return  noOfLeafNodes(root->left ) + noOfLeafNodes(root->right);
} 


int countNodes ( BinaryTreeNode <int> *root ){
    if ( root == NULL) {
        return 0;
    }

    return 1 + countNodes(root->left ) + countNodes(root->right);

}



int main()
{
    BinaryTreeNode<int>* n0 = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int>* n1 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int>* n2 = new BinaryTreeNode<int>(3);
    BinaryTreeNode<int>* n3 = new BinaryTreeNode<int>(4);
    BinaryTreeNode<int>* n4 = new BinaryTreeNode<int>(5);
    BinaryTreeNode<int>* n5 = new BinaryTreeNode<int>(6);

    n0->left = n1;
    n0->right = n2;

    n1->left = n3;
    n1->right = n4;

    n2->left = n5;


    int ans = noOfLeafNodes(n0);
    cout << "Leaf Nodes  : " << ans << endl;

    int val = countNodes(n0);
    cout << "Total Nodes : " << val << endl;


    delete n0;
    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;

    return 0;
}