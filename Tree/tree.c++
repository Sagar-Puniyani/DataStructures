#include <iostream>
#include <queue>
using namespace std;

class node {

    public:
    int data;
    node* left;
    node* right;

    node( int data ){
        (*this).data = data;
        (*this).left = NULL;
        (*this).right = NULL;

    }
};


void levelorderTraversal( node* root ){
    queue <node*> q;
}


int main()
{
    
    return 0;
}