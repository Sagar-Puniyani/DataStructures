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

void kthLargestBST(TreeNode* root , int &count , int k , int &ans ) {
    if ( root == NULL )  return;

    //Right 
    kthLargestBST(root->right , count , k , ans );

    // Node 
    count ++;
    if ( k == count ){
        ans = root->val;
        return;
    }

    // Left 
    kthLargestBST( root->left , count , k , ans );

}


int kthLargest(TreeNode* root, int k) {
    int count = 0;
    int ans;
    kthLargestBST( root , count , k , ans );
    return ans;
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

    cout << "Kth largest BST " << endl;
    int ans = kthLargest(n5 , 3);
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


    return 0;
}