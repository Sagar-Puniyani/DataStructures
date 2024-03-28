#include <iostream>
#include <vector>
using namespace std;


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x) : data(x) , left(NULL) , right(NULL){}
};


pair <int , int> solution ( Node* root ){
    //base case 
    if ( root == NULL ) return { 0 , 0 };

    pair <int , int> Left = solution(root->left );
    pair <int , int> Right = solution(root->right );


    pair <int , int> ans; 
    ans.first = root->data + Left.second + Right.second;
    ans.second = max( Left.first , Left.second ) + max( Right.first , Right.second);

    return ans;

}


int getMaxSum(Node *root) {
    pair<int , int> p = solution(root);
    return max( p.first , p.second );
}



int  main(){
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);

    
    
    n1->left = n2;
    n1->right = n3;

    n2->left = n4;

    n3->left = n5;
    n3->right = n6;


    int ans = getMaxSum(n1);
    cout << "Ans : " << ans << endl;

    
    
    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;
    delete n6;


    return 0;
}