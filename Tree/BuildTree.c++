#include <iostream>
#include <queue>
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


Node* BuildTree( vector<int> preorder , int psi , int pei , vector<int> inorder , int isi , int iei , map<int , int >map){
    /*
    cout << "psi = " << psi<< endl;
    cout << "pei = " << pei<< endl;
    cout << "isi = " << isi<< endl;
    cout << "iei = " << iei<< endl;
    */
    
    if (isi > iei ) return nullptr;

   //cout << "preorder[psi] = "<< preorder[psi] << endl;
    int index = map[preorder[psi]];
    //cout << "index = " << index << endl;
    int Size =  index - isi;

    Node* node = new Node(preorder[psi]);

    node->left = BuildTree(preorder, psi + 1, psi + Size, inorder, isi, index - 1 , map );
    node->right = BuildTree(preorder, psi + Size + 1, pei, inorder, index + 1, iei , map);


    return node;

}


Node* buildTree( vector<int> preorder,  vector<int> inorder) {
    int n = preorder.size();
    cout << " n = " <<n <<endl;
    map <int , int > map = CreateMap(inorder);
    Node* ans = BuildTree(preorder , 0 , n-1 , inorder , 0 , n-1 , map );
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



int  main(){
    vector <int>  in = {2 ,1,3 };
    vector <int>  pre  = {1,2,3};

    Node* ans = buildTree(pre , in  );
    cout << "InOder : " << endl;
    Inorder(ans);
    cout << endl;
    cout << "PreOrder  : " << endl;
    preorder(ans);
    cout << endl;
    cout <<"PostOrder : " <<  endl;
    postorder(ans);
    cout << endl;
    cout <<"LevelOrderTraversal : " <<  endl;
    levelorderTraversal(ans);


    return 0;
}