#include <iostream>
#include <map>
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


void print (pair <int ,int > p  ){
    auto [key , value ]  = p;
    cout << "< " << key << " , " << value << " > " <<  endl;
}

void solution ( Node* root , pair <int , int> & p , int sum , int len ){
    // base case 
    if ( root == NULL ) return;

    if ( root->left == NULL && root ->right == NULL ){
        if (p.second < len ){
            p.second = len;
            p.first = sum + root->data;
        }

        if ( len == p.second ){
            int MaxSum = max(sum + root->data , p.first );
            p.first = MaxSum;
        }
        return ; 
    }

    else {
        sum += root->data;

    if ( root -> left )
        solution ( root->left ,  p ,  sum ,  len+1);

    if ( root->right )
        solution ( root->right ,  p ,  sum  ,  len+1);

    }

}


int sumOfLongRootToLeafPath(Node *root){
    // critical case 
    if ( root == NULL ) return 0;

    pair <int , int > p;

    p = make_pair( root->data , 1 );

    solution(root , p , 0 , 1 );

    return p.first;
}


int main()
{

    Node* n1 = new Node(4);
    Node* n2 = new Node(2);
    Node* n3 = new Node(5);
    Node* n4 = new Node(7);
    Node* n5 = new Node(1);
    Node* n6 = new Node(2);
    Node* n7 = new Node(3);
    Node* n8 = new Node(6);
    
    
    n1->left = n2;
    n1->right = n3;

    n2->left = n4;
    n2->right = n5;

    n3->right = n6;
    n3->right = n7;

    n5->left = n8;


    int  ans = sumOfLongRootToLeafPath(n1);
    cout << " ans = " << ans << endl; 


    
    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;
    delete n6;
    delete n7;
    delete n8;


    return 0;
}