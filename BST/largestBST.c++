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

class info
{
    public: 
    int maxi;
    int mini;
    bool isBST;
    int sum;
};

info solve(TreeNode* root, int &ans)
{
    // base case
    if(root==NULL)
    {
        return {INT_MIN, INT_MAX, true, 0};
    }

    info left=solve(root->left, ans);
    info right=solve(root->right, ans);

    info currNode;

    currNode.sum=left.sum + right.sum + root->val;
    currNode.maxi=max(root->val, right.maxi);
    currNode.mini=min(root->val, left.mini);

    if(left.isBST && right.isBST && (root->val > left.maxi && root->val < right.mini))
    {
        currNode.isBST=true;
    }
    else
    {
        currNode.isBST=false;
    }

    // answer update
    if(currNode.isBST)
    {
        ans=max(ans, currNode.sum);
    }

    return currNode;
}

int largestBST(TreeNode * root){
    int maxSize;
    info temp = solve(root , maxSize);
    return maxSize;
}


int main(){
    TreeNode* n1 = new TreeNode(2);
    TreeNode* n2 = new TreeNode(1);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(0);
    TreeNode* n5 = new TreeNode(1);



    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;
}