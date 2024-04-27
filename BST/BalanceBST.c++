#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class TreeNode
{
public :
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data) : data(data), left(nullptr), right(nullptr) {}

    ~TreeNode() {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

void print( vector<int> arr ){
    for ( auto item : arr ){
        cout << "  " << item ;
    }
    cout << endl;
}


void Inorder(TreeNode<int>* root , vector <int> &in ){
    if( root == NULL ) return;

    Inorder(root->left , in);
    in.push_back(root->data);
    Inorder(root->right , in);
}

TreeNode<int>* helper(vector<int> arr , int start , int end ){
    if ( start > end ) return nullptr;

    int mid = start + ( end - start )/2;

    TreeNode<int>* newNode = new TreeNode<int>(arr[mid]);
    newNode->left = helper(arr , start , mid-1);
    newNode->right = helper(arr , mid+1 , end );

    return newNode;
}


TreeNode<int>* balancedBst(TreeNode<int>* root) {
    vector<int> arr;
    Inorder(root , arr);

    cout << "Helper " << endl;
    TreeNode<int>* NewNode = helper( arr , 0 , arr.size()-1);

    return NewNode;
}

void traversal( TreeNode<int>* root ){
    if ( root == NULL ) return;

    traversal(root->left);
    traversal(root->right);
    cout << "  " << root->data ;
}




int main(){
    
    TreeNode<int>* n1 = new TreeNode<int>(10);
    TreeNode<int>* n2 = new TreeNode<int>(8);
    TreeNode<int>* n3 = new TreeNode<int>(12);
    TreeNode<int>* n4 = new TreeNode<int>(4);
    TreeNode<int>* n5 = new TreeNode<int>(16);
    TreeNode<int>* n6 = new TreeNode<int>(2);
    TreeNode<int>* n7 = new TreeNode<int>(20);

    n1->left = n2;
    n1->right = n3;

    n2->left = n4;

    n3->right = n5;

    n4->left = n6;

    n5->right = n7;

    cout << "Post Order " << endl;
    traversal(n1);
    cout << endl;

    cout <<"Balance BST" << endl;
    TreeNode<int>* root =  balancedBst(n1);
    traversal(root);
    cout << endl;



    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;
    delete n6;
    delete n7;


    return 0;
}