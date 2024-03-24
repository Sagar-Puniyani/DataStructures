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


vector<int> verticalOrder(Node *root){
    map <int, map< int , vector <int>>> map;
    queue < pair< Node* , pair<int , int>>> q;
    vector<int> ans;

    // critical case 
    if ( root == NULL ){
        return ans;
    }

    q.push(make_pair(root , make_pair( 0 , 0)));

    while ( !q.empty() ){
        pair< Node* , pair<int , int>> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int row = temp.second.first;
        int col = temp.second.second;

        map[row][col].push_back(frontNode->data);

        if ( frontNode->left )
            q.push(make_pair(frontNode->left , make_pair(row-1 , col+1)));

        if ( frontNode->right)
            q.push(make_pair(frontNode->right , make_pair(row+1 , col+1)));
    }

    for (auto  item : map){
        for ( auto rowItem : item.second ){
            for ( auto listItem : rowItem.second){
                ans.push_back(listItem);
            }
        }
    }

    return ans;
}

int main()
{

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