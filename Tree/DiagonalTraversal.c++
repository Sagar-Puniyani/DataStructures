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

void print(queue<Node*> arr) {
    while (!arr.empty()) {
        cout << arr.front()->data << " ";
        arr.pop();
    }
    cout << endl;
}


void solution(  Node* root , vector<int>& ans , queue <Node* > &q ){
    cout << "Queue : " << endl;
    print(q);
    if ( root == NULL ){
        return;
    }

    else {
        if ( root->left){
            q.push(root->left);
        }
            ans.push_back(root->data);
            solution(root->right , ans , q );


    }
}

vector<int> diagonal(Node *root){
    vector <int> ans;
    queue <Node* > q;

    if ( root == NULL ) return ans;

    q.push(root);

    while (!q.empty() ){
        solution( q.front() , ans , q );
        q.pop();

    }
    return ans;
}



int main()
{

    Node* n1 = new Node(8);
    Node* n2 = new Node(3);
    Node* n3 = new Node(10);
    Node* n4 = new Node(1);
    Node* n5 = new Node(6);
    Node* n6 = new Node(14);
    Node* n7 = new Node(4);
    Node* n8 = new Node(7);
    Node* n9 = new Node(13);
    
    
    n1->left = n2;
    n1->right = n3;

    n2->left = n4;
    n2->right = n5;

    n3->right = n6;

    n5->left = n7;
    n5->right = n8;

    n6->left = n9;


    vector <int> ans = diagonal(n1);
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