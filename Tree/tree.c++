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

node* buildTree(node* root){
    cout << "Enter data :" ;
    int data;
    cin >> data;
    root  = new node(data);

    if ( data == -1 ){
        return NULL;
    }

    cout << "Enter left data :" << endl;
    root->left = buildTree(root->left);

    cout << "Enter right data :" << endl;
    root->right = buildTree(root->right);

    return root;
}


void levelorderTraversal( node* root ){
    queue <node*> q;
    q.push(root);

    while ( !q.empty() ) {
        node* temp = q.front();
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


int main()
{
    int a = 10;
    cout << "a = "<< a << endl;
    cout << "&a = "<< &a << endl;

    int* ptr = &a;
    cout << "ptr = " << ptr << endl;
    cout << "&ptr = " << &ptr << endl;
    cout << "*ptr = " << *ptr << endl;

    node* n;
    n = buildTree(n);
    levelorderTraversal(n);

    return 0;
}