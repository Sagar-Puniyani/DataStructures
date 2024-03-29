#include <iostream>
#include <map>
#include <vector>
using namespace std;


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x) : data(x) , left(NULL) , right(NULL){}
};
void printMap( map <int , int > map ){
    for ( auto [key , value ] : map ){
        cout << key << " = " << value << endl;
    }
}

map <int , int > CreateMap(vector <int> inorder ) {
    map <int , int> map;
    for ( int i=0 ; i<inorder.size() ; i++ ){
        map[inorder[i]] = i;
    }
    printMap(map);
    return map;
}

Node* BuildTree( vector<int> postorder , int psi , int pei , vector<int> inorder , int isi , int iei , map<int , int >map){


    cout << "psi = " << psi<< endl;
    cout << "pei = " << pei<< endl;
    cout << "isi = " << isi<< endl;
    cout << "iei = " << iei<< endl;
    
    if (isi > iei || psi > pei) return nullptr;

    int index = map[postorder[pei]];
    int Size =  iei - index;
    // zise of right 
    cout << "Size = " << Size << endl;

    Node* node = new Node(postorder[pei]);

    node->left = BuildTree(postorder, psi , pei-Size-1, inorder, isi, index - 1 , map );
    node->right = BuildTree(postorder, pei-Size , pei-1, inorder, index + 1, iei , map);


    return node;

}


Node* buildTree( vector<int> postorder,  vector<int> inorder) {
    int n = postorder.size();
    cout << " n = " <<n <<endl;
    map <int , int > map = CreateMap(inorder);
    Node* ans = BuildTree(postorder , 0, n-1 , inorder , 0 , n-1 , map );
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
    vector <int>  in = {9,3,15,20,7};
    vector <int>  post  = {9,15,7,20,3};

    Node* ans = buildTree(post , in );
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