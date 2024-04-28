#include <iostream>
#include <vector>
#include <algorithm>
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

void print( vector<int> arr ){
    for ( auto item : arr ){
        cout << "  " << item ;
    }
    cout << endl;
}


vector<int> Inorder( TreeNode *root , vector<int> &in){
    if ( root == NULL ) return in ;
    
    Inorder(root->left , in);
    in.push_back(root->data);
    Inorder(root->right , in);

    return in;
}

TreeNode* helper(vector<int> arr , int start , int end ){
    if ( start > end ) return nullptr;

    int mid = start + ( end - start )/2;

    TreeNode* newNode = new TreeNode(arr[mid]);
    newNode->left = helper(arr , start , mid-1);
    newNode->right = helper(arr , mid+1 , end );

    return newNode;
}

void BSTtosortedDLL(TreeNode* root , TreeNode* head ) {
    if ( root == NULL ) return;

    BSTtosortedDLL(root->right , head);

    root->right = head;
    if( head != NULL ) 
        head->left = root;
    
    head = root;

    BSTtosortedDLL(root->left , head);
}

TreeNode* Merge_two_DLL(TreeNode* head1 , TreeNode* head2){

    if (!head1) 
        return head2; 

    if (!head2) 
        return head1; 


    if (head1->data  < head2->data) 
    { 
        head1->right = Merge_two_DLL(first->next,second); 
        head1->right->left = head1; 
        head1->left = NULL; 
        return head1; 
    } 
    else
    { 
        head2->right = Merge_two_DLL(first,second->next); 
        head2->right->left = second; 
        head2->left = NULL; 
        return head2; 
    } 
}

int NodeCount( TreeNode* head ){
    if ( head == NULL ) return 0;

    int count = 0;
    while ( head != NULL ){
        count++;
        head = head->right;
    }
    return count;
}

TreeNode* SortedDLLtoBST(TreeNode* &head , int n ){

    if ( n<=0 || head == NULL ) return NULL;

    TreeNode* LeftSubTree = SortedDLLtoBST(head , n/2);

    TreeNode*root = head;
    root->left = LeftSubTree;


    head = head->right;

    root->right = SortedDLLtoBST(head , n/2 );
    return root;
}


TreeNode* MergeBSTbyDLL(TreeNode* root1 , TreeNode* root2){
    TreeNode* head1 = NULL;
    TreeNode* head2 = NULL;

    BSTtosortedDLL(root1 , head1);
    BSTtosortedDLL(root2 , head2);
    head1->left = NULL;
    head2->left = NULL;

    TreeNode * head = Merge_two_DLL(head1 , head2);

    return SortedDLLtoBST(head , NodeCount(head));

}


vector<int> mergeBST(TreeNode *root1, TreeNode *root2){
    vector<int> arr1 , arr2 , arr3;
    arr1 = Inorder(root1 , arr1);
    arr2 = Inorder(root2 , arr2);

    print(arr1);
    print(arr2);

    cout << "arr1.begin() = " << *(arr1.begin()) << endl;
    cout << "arr1.end() = " << *(arr1.end()-1) << endl;
    cout << "arr2.begin() = " << *(arr2.begin()) << endl;
    cout << "arr2.end() = " << *(arr2.end()-1) << endl;
    arr3.resize(arr1.size() + arr2.size());

    merge(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), arr3.begin());
    sort(arr3.begin(), arr3.end());
    helper(arr3 , 0 , arr3.size()-1);
    cout << "Array 3 " << endl;
    print(arr3);

    return arr3;
}

int main() {
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);

    n2->left = n1;
    n2->right = n3;


    TreeNode* n4 = new TreeNode(4);

    vector <int> arr = mergeBST(n2 , n4);


    return 0;
}