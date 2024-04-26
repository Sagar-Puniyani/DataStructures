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

void Inorder(TreeNode* root , vector <int> &in ){
    if( root == NULL ) return;

    Inorder(root->left , in);
    cout << "root->val : " << root->val << endl;
    in.push_back(root->val);
    Inorder(root->right , in);
}


bool findTarget(TreeNode* root, int k) {
    vector <int> arr ;
    Inorder(root , arr );

    int i = 0;
    int j = arr.size() -1;
    cout << " arr.size() = " << arr.size() << endl;
    cout << " j = " << j << endl;

    while( i < j ){
        cout << "arr[i] = " << arr[i] << "  " << "arr[j] = " << arr[j] << endl;
        int sum = arr[i] + arr[j];

        if ( sum == k ) return true;
        else if ( sum > k )  j--;
        else i++;
    }

    return false;
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


    cout <<"Two sum in BST" << endl;
    bool ans = findTarget(n1 , 20);
    cout << "Ans : " << ans <<  endl;

    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;
    delete n6;
    delete n7;


    return 0;
}