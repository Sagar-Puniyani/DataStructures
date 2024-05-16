#include <iostream>
using namespace std;


class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};



bool evaluateTree(TreeNode* root) {
    if (root->left == NULL && root->right == NULL) 
        return root->data;
    
    if (root->data == 2){
        return evaluateTree(root->left) || evaluateTree(root->right);
    }

    else {
        return evaluateTree(root->left) && evaluateTree(root->right);
    }

}

int main(){
    TreeNode* n1 = new TreeNode(2);
    TreeNode* n2 = new TreeNode(1);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(0);
    TreeNode* n5 = new TreeNode(1);

    n1->left = n2;
    n1->right = n3;

    n3->left = n4;
    n3->right = n5;



    bool ans = evaluateTree(n1);
    cout << "Evaluation of boolean Full Binary Tree : " << ans << endl;


    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;
}