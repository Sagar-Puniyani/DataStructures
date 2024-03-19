#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x) : data(x) , left(NULL) , right(NULL){}
};


pair <bool , int> SumTree ( Node * root ){
    // base case 
    if ( root == NULL ){
        return {true , 0};
    }
    if ( root->left == NULL && root->right == NULL ){
        return { true , root->data };
    }

    else {
        auto left = SumTree(root->left);
        auto right = SumTree(root->right);

        bool Sumcheck  =  left.first && right.first && (root->data == left.second + right.second );
        int sum = left.second + right.second + root->data;

        return {Sumcheck , sum};
    }
}


bool isSumTree(Node* root){
    return SumTree( root ).first;
}


int main(){
    Node* n1 = new Node(70);
    Node* n2 = new Node(20);
    Node* n3 = new Node(30);
    Node* n4 = new Node(10);
    Node* n5 = new Node(10);
    
    n1->left = n2;
    n1->right = n3;

    n2->left = n4;
    n2->right = n5;

    bool ans = isSumTree(n1);
    cout << "Is Sum Tree : " << ans << endl;
    
    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;

    return 0;
}