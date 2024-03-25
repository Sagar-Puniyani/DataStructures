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

void print(vector <int> arr ){
    for ( auto item : arr ){
        cout << item << "  ";
    }
    cout << endl;
}



vector<int> rightView(Node *root){
    map < int , pair <int , Node* >> map;
    queue < pair<pair<int , int > , Node* >> q;
    vector<int> ans;

    // Critical case
    if (root == NULL ){
        return ans;
    }

    q.push( make_pair(make_pair( 0 , 0 ) , root));

    while ( !q.empty() ){
        pair<pair<int , int > , Node* > temp = q.front();
        q.pop();

        Node* frontNode  = temp.second;
        int row = temp.first.first;
        int col = temp.first.second;

        map[row] = make_pair( col , frontNode );

        if ( frontNode->left ){
            q.push(make_pair(make_pair( row + 1, col - 1 ) , frontNode->left));
        }

        if ( frontNode->right ) {
            q.push(make_pair(make_pair( row + 1 , col + 1 ) , frontNode->right));
        }

    }

    for ( auto &item : map ){
        pair<int, Node*> temp = item.second;
        ans.push_back(temp.second->data);
    }
    return ans;

}


int  main(){
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    Node* n7 = new Node(7);
    Node* n8 = new Node(8);
    Node* n9 = new Node(9);
    
    
    n1->left = n2;
    n1->right = n6;

    n2->left = n3;
    n2->right = n4;

    n4->right = n5;

    n6->right = n7;

    n7->right = n8;

    n8->right = n9;
    
    vector <int> ans = rightView(n1);
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
    
    return 0;
}