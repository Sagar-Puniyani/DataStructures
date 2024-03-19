#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

int height(struct Node* node){

    if ( node == NULL){
        return 0;
    }
    else {
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        return max(leftHeight , rightHeight ) + 1;
    }
}

 bool isBalanced(Node *root){
    // base case 
    if ( root == NULL ){
        return true;
    }
    else {
        

        bool leftBalance = isBalanced(root->left);
        bool rightBalance = isBalanced(root->right);

        bool HeightDiff = abs (height(root->left) - height(root->right)) <= 1;

        return (leftBalance && rightBalance && HeightDiff);
    }
}


pair<bool , int > TreeBalanced ( Node * root ){
     // base case 
    if ( root == NULL ){
        pair<bool , int > p = make_pair( true , 0);
        return p;
    }
    else {
        pair < bool , int> left = TreeBalanced(root->left);
        pair < bool , int> right = TreeBalanced(root->right);

        bool leftBalance = left.first;
        bool rightBalance = right.first;
        bool HeightDiff = abs (left.second - right.second) <= 1;

        pair< bool , int > p;
        p.first = leftBalance && rightBalance && HeightDiff;
        p.second = max( left.second , right.second ) + 1;
        return p;
    }
}

bool IsBalancedTree( Node* root ){
    return TreeBalanced(root).first;
}

int main()
{
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);

    n1->left = n2;
    n1->right = n3;

    n2->left = n4;
    n2->right = n5;

    bool ans = isBalanced(n1);
    cout << "Is Balanced : " << ans << endl;

    bool ans1 = IsBalancedTree(n1);
    cout << "Is Balanced : " << ans1 << endl;

    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;
    return 0;
}