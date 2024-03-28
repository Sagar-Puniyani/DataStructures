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




Node* BuildTree( vector<int> preorder , int psi , int pei , vector<int> inorder , int isi , int iei ){
    cout << "isi = " << isi<< endl;
    cout << "iei = " << iei<< endl;
    if (isi > iei ) return nullptr;

    int index = isi;
    while ( inorder[index] != preorder[psi] ) index++;
    cout << "index = " << index << endl;
    int leftSize =  index - isi;
    int rightSize = iei - index;

    Node* node = new Node(preorder[psi]);

    node->left = BuildTree(preorder, psi + 1, psi + leftSize, inorder, isi, index - 1);
    node->right = BuildTree(preorder, psi + leftSize + 1, pei, inorder, index + 1, iei);


    return node;

}


Node* buildTree( vector<int> preorder,  vector<int> inorder) {
    int n = preorder.size();
    cout << " n = " <<n <<endl;
    Node* ans = BuildTree(preorder , 0 , n-1 , inorder , 0 , n-1);
    return ans;
}

void Inorder( Node* root ){
    if ( root == NULL ){
        return;
    }

    Inorder(root->left);
    cout <<"  " <<  root->data ;
    Inorder(root->right);
}

void postorder( Node* root ){
    if ( root == NULL ){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout <<"  " <<  root->data ;
}

void preorder( Node* root ){
    if ( root == NULL ){
        return;
    }

    cout <<"  " <<  root->data ;
    preorder(root->left);
    preorder(root->right);
}



int  main(){
    vector <int>  in = {1 , 6 , 8 , 7};
    vector <int>  pre  = { 1 , 6 , 7 , 8 };

    Node* ans = buildTree(in , pre  );
    cout << "InOder : " << endl;
    Inorder(ans);
    cout << endl;
    cout << "PreOrder  : " << endl;
    preorder(ans);
    cout << endl;
    cout <<"PostOrder : " <<  endl;
    postorder(ans);


    return 0;
}