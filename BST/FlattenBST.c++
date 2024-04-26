#include <iostream>
#include <vector>
using namespace std;


struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    
    TreeNode(int x) {
        this->val  = x;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void print( TreeNode* root){
    while( root != NULL ){
        cout << "  " << root->val ;
        root = root->right;
    }
}


void Inorder(TreeNode* root , vector <TreeNode*> &in ){
    if( root == NULL ) return;

    Inorder(root->left , in);
    in.push_back(root);
    Inorder(root->right , in);
}

TreeNode* flatten(TreeNode* root){
    vector <TreeNode*> arr;
    Inorder(root , arr);
    cout << "Flatten " << endl;
    cout << "Size :  "<< arr.size() << endl;

    int i=0;
    while( i <= arr.size()-2 ){
        cout << "Data : " << arr[i]->val << endl;
        arr[i]->left = NULL;
        arr[i]->right = arr[i+1];
        i++;
    }

    arr[arr.size()-1]->left = nullptr;
    arr[arr.size()-1]->right = nullptr;

    return arr[0];
}


int main(){
    TreeNode* n1 = new TreeNode(10);
    TreeNode* n2 = new TreeNode(6);
    TreeNode* n3 = new TreeNode(12);
    TreeNode* n4 = new TreeNode(2);
    TreeNode* n5 = new TreeNode(8);
    TreeNode* n6 = new TreeNode(11);
    TreeNode* n7 = new TreeNode(15);

    n1->left = n2;
    n1->right = n3;

    n2->left = n4;
    n2->right = n5;

    n3->left = n6;
    n3->right = n7;


    cout <<"Flatten BST" << endl;
    TreeNode* root = flatten(n1);
    print(root);

    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;
    delete n6;
    delete n7;


    return 0;
}