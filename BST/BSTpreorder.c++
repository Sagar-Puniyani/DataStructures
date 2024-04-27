#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


void print ( vector <int> arr ){
    for  ( auto item : arr ){
        cout << " " << item ;
    }
}

void traversal ( TreeNode * root ){
    if (root == NULL ) return;

    cout << " " << root->val;
    traversal(root->left);
    traversal(root->right);
}


TreeNode* solve( vector<int> &preorder ,  int &i ,  int min_range ,  int max_range  ){
    if ( i >=  preorder.size() ) return nullptr;

    else if ( min_range > preorder[i] || max_range < preorder[i]) return nullptr;

    TreeNode* newNode = new TreeNode(preorder[i++]);
    newNode->left = solve(preorder , i , min_range , newNode->val);
    newNode->right = solve(preorder, i , newNode->val , max_range);

    return newNode;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    int index = 0;
    TreeNode* NewNode = solve(preorder , index , INT_MIN , INT_MAX);
    return NewNode;
}


int main(){
    vector<int> arr = {8,5,1,7,10,12};

    cout << "Pre Order" << endl;
    print(arr);
    cout << endl;

    cout << "Tree " << endl;
    TreeNode* root = bstFromPreorder(arr);
    traversal(root);
    cout << endl;

    return 0;
}
