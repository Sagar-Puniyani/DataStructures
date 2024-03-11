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

    cout << "Enter left data of  " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter right data  " << data << endl;
    root->right = buildTree(root->right);

    return root;
}


void Inorder( node* root ){
    if ( root == NULL ){
        return;
    }

    Inorder(root->left);
    cout <<"  " <<  root->data ;
    Inorder(root->right);
}

void preorder( node* root ){
    if ( root == NULL ){
        return;
    }

    cout <<"  " <<  root->data ;
    preorder(root->left);
    preorder(root->right);
}
void postorder( node* root ){
    if ( root == NULL ){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout <<"  " <<  root->data ;
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


void  buildLevelTree( node * &root ){
    queue < node* > q;
    cout << "Enter data for root "<< endl;
    int data;
    cin >> data;
    root = new node( data );
    q.push(root);

    while ( !q.empty() ){
        node* temp = q.front();
        q.pop();

        cout << "Enter left data : " << endl;
        int leftData ;
        cin >> leftData;

        if ( leftData != -1 ){
            temp -> left = new node( leftData);
            q.push(temp->left);
            
        }
        cout << "Enter right data : " << endl;
        int rightData ;
        cin >> rightData;

        if ( rightData != -1 ){
            temp -> right = new node( rightData);
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
    /*
    n = buildTree(n);

    cout << endl;
    cout << "Level Order "<< endl;
    levelorderTraversal(n);

    cout << endl;
    cout << "Inorder "<< endl;
    Inorder(n);

    cout << endl;
    cout << "preorder "<< endl;
    preorder(n);

    */

    buildLevelTree(n);
    cout << endl;
    cout << "Postorder" << endl;
    postorder(n);


    return 0;
}