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


pair<int , int > Diameter( Node * root ){
    // base case 
    if ( root == NULL ){
        pair < int , int > p = make_pair( 0 , 0 );
        return p;
    }
    else {
        pair<int , int> left = Diameter(root->left);
        pair<int , int> right = Diameter(root->right);

        int leftDiameter = left.first;
        int rightDiameter = right.first;
        int RootDiameter = left.second  + right.second;

        int FinalDiameter = max( leftDiameter , max(rightDiameter , RootDiameter));

        int leftHeight = left.second;
        int rightHeight = right.second;

        int FinalHeight = max( leftHeight , rightHeight ) + 1;
        pair<int , int> p = make_pair( FinalDiameter , FinalHeight);
        return p;
    }
}

int diameterLogic( Node* root ){
    pair <int , int > p = Diameter(root);
    return p.first;
}

int diameter( Node* root ){
    // base case 
    if ( root == NULL ){
        return 0;
    }
    else {
        int leftDiameter = diameter(root->left);
        int rightDiameter = diameter( root->right );
        int RootDiameter = height(root->left ) + height( root->right );

        return max( leftDiameter , max(rightDiameter , RootDiameter));
    }
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

    int ans = height(n1);
    cout << "Height : " << ans << endl;

    int Diameter = diameter( n1 );
    cout << "Diameter : "  << Diameter << endl;

    int Diameter1 = diameterLogic( n1 );
    cout << "Diameter1 : "  << Diameter1 << endl;


    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;


    return 0;
}