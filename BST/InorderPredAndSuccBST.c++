#include <iostream>
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

int Predecssor(TreeNode* root , int key ){
    
    int pred = -1;
    while( root != NULL ){
        if ( root->val >= key ){
            root = root->left;
        }
        else {
            pred = root->val;
            cout << "Pred : " << pred << endl;
            root = root->right;
        }
    }
    return pred;
}
int Successor(TreeNode* root , int key ){
    int succ = -1;
    while( root != NULL ){
        if ( root->val <= key ){
            root = root->right;
        }
        else {
            succ = root->val;
            cout << "Succ : " << succ << endl;
            root = root->left;
        }
    }
    return succ;
}


pair<int, int> predecessorSuccessor(TreeNode *root, int key){
    pair<int , int > p;
    p.first = Predecssor(root , key );
    p.second = Successor(root , key );
    return p;
}


int main(){
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5);
    TreeNode* n6 = new TreeNode(6);
    TreeNode* n7 = new TreeNode(7);
    TreeNode* n8 = new TreeNode(8);
    TreeNode* n9 = new TreeNode(9);
    TreeNode* n10 = new TreeNode(10);

    n5->left = n4;
    n5->right = n8;

    n4->left = n2;

    n2->right = n3;

    n8->left = n6;
    n8->right = n10;

    n6->right = n7;

    cout << "Inorder  Predecessor And Successor In BST : " << endl;
    pair <int , int > p = predecessorSuccessor(n5 , 6);
    auto [ Predecessor , Successor ] = p;
    cout << "first "<< Predecessor << "," << "second " << Successor << endl;

    /*
    int ans = Successor(n5 , 4);
    cout << "Ans : " << ans << endl;

    int pred = Predecssor(n5 , 6);
    cout << "Pred : " << pred << endl;
    */


    delete n2;
    delete n3;
    delete n4;
    delete n5;
    delete n6;
    delete n7;
    delete n8;
    delete n9;
    delete n10;


    return 0;
}