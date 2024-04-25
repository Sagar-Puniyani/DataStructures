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

int kthSmallestBST(TreeNode* root , int &count , int k ) {
    if ( root == NULL ) {
        return -1;
    }
    // Left 
    int leftAns = kthSmallestBST( root->left , count , k );
    if ( leftAns != -1 ) return leftAns;

    // Node 
    count ++;
    if ( k == count ){
        return root->val;
    }

    //Right 
    return kthSmallestBST(root->right , count , k);
}


int kthSmallest(TreeNode* root, int k) {
    int count = 0;
    return kthSmallestBST( root , count , k );
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

    int ans = kthSmallest(n5 , 3);
    cout << "Ans : " << ans << endl;


    delete n2;
    delete n3;
    delete n4;
    delete n5;
    delete n6;
    delete n7;
    delete n8;
    delete n9;
    delete n10;


    return 1;
}