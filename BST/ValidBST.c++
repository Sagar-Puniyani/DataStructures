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
bool isBST(TreeNode* root , long long int min , long long int max ){
    if ( root == NULL )  return true;

    bool result = false;
    if (min < root->val && max > root->val ) result = true;
    return result && isBST(root->left,min,root->val) 
                && isBST(root->right , root->val , max);
}

bool isValidBST(TreeNode* root) {
    return isBST( root , LLONG_MIN , LLONG_MAX );
}


int main(){
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);

    n2->left = n1;
    n2->right = n3;

    cout << "Vslidate : " << INT_MAX << "  , " << INT_MIN <<endl;
    bool ans = isValidBST(n2);
    cout << "Ans : " << ans << endl;
    delete n1;
    delete n2;
    delete n3;


    return 1;
}