#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x) : data(x) , left(NULL) , right(NULL){}
};

void  print ( vector <int> arr ){
    for ( auto element : arr ){
        cout << element << "  ";
    }
    cout << endl;
}


void LeftPathTraversal( Node* root , vector <int> & ans ){

    // base case 
    if ( ( root == NULL ) || ( root->left == NULL && root->right == NULL )){
        return;
    }

    else {
        ans.push_back(root->data);
        if ( !root->left ) LeftPathTraversal(root->right , ans );
        else LeftPathTraversal( root->left , ans);
    }
}


void RightPathTraversal( Node* root , vector <int> &ans ){

    // base case 
    if ( ( root == NULL ) || ( root->left == NULL && root->right == NULL )){
        return;
    }

    else {
        if ( root->right == NULL ) {
            RightPathTraversal(root->left , ans );
        }
        else{
            RightPathTraversal( root->right  , ans  );
        }
        ans.push_back(root->data);
    }
}

void TraverseChildNode( Node* root  , vector <int> &ans){
    // base case 
    if ( root == NULL )
        return;

    else if ( root->left == NULL  && root->right == NULL ){
        ans.push_back(root->data);
        return;
    }
    else {
        TraverseChildNode(root->left , ans );
        TraverseChildNode(root->right , ans );
    }
}

void levelorderTraversal( Node* root ){
    queue <Node*> q;
    q.push(root);

    while ( !q.empty() ) {
        Node* temp = q.front();
        cout << temp->data << " " ;
        q.pop();

        if ( temp->left ) {
            q.push(temp->left);
        }
        if ( temp->right ) {
            q.push(temp->right);
        }
    }
}

vector <int> boundary(Node *root){

    vector <int> ans;

    // critical  case 
    if ( root == NULL ){
        return ans;
    }
    else if ( root->left == NULL && root->right == NULL ){
        ans.push_back(root->data);
        return ans;
    }
    else {
        ans.push_back(root->data);

        // left path 
        LeftPathTraversal(root->left , ans );

        // Traverse Child Nodes 
        TraverseChildNode(root , ans );

        // Right Path 
        RightPathTraversal(root->right , ans );
    }

    return ans;

}


int main(){
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    Node* n7 = new Node(7);
    Node* n8 = new Node(8);
    Node* n9 = new Node(9);
    Node* n10 = new Node(10);
    Node* n11 = new Node(11);
    
    n1->left = n2;
    n1->right = n4;

    n2->left = n3;
    n2->right = n5;

    n4->right = n7;

    n5->left = n6;
    n5->right = n8;

    n7->right = n9;

    n9->left = n10;
    n9->right = n11;

    /*LeftPathTraversal(n1);
    cout << endl;
    RightPathTraversal(n1->right);
    cout << endl;
    TraverseChildNode(n1);
    cout << endl;*/


    vector <int> ans = boundary(n11);
    cout << "ans : " ; 
    print(ans);
    
    
    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;
    delete n6;
    delete n7;
    delete n8;
    delete n9;
    delete n10;
    delete n11;



    return 0;
}