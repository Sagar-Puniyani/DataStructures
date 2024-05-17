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

void Inorder(TreeNode* root ){
    if ( root == NULL ) 
        return;

    Inorder(root->left);
    cout << " " << root->data;
    Inorder(root->right);
}


TreeNode* removeLeafNodes(TreeNode* root, int target) {

    if ( root == NULL ) return NULL;

    root->left = removeLeafNodes(root->left , target);
    root->right = removeLeafNodes(root->right , target);

    if (root->left == NULL && root->right == NULL && root->data == target){
        return nullptr;
    }

    return root;

}

int main(){
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(2);
    TreeNode* n5 = new TreeNode(2);
    TreeNode* n6 = new TreeNode(4);

    n1->left = n2;
    n1->right = n3;

    n2->left = n4;

    n3->left = n5;
    n3->right = n6;


    Inorder(n1);
    cout << endl;
    TreeNode* ans = removeLeafNodes(n1 , 2);
    cout << "Removing target Node from tree : " <<  endl;
    Inorder(ans);

    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;
    delete n6;
}