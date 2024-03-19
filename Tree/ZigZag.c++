#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x) : data(x) , left(NULL) , right(NULL){}
};

void  print ( vector <int> arr ){
    for ( auto element : arr ){
        cout << element << "  ";
    }
    cout << endl;
}

vector <int> zigZagTraversal(Node* root){

    vector <int> result;
    queue<Node*> q;
    
    // critical case 
    if ( root == NULL ){
        return result;
    }
    q.push(root);
    bool LeftToRight = true;

    while ( !q.empty() ) {
        
        int size = q.size();
        vector <int> ans(size);
        cout << "Size : " << size << endl;

        for ( int i=0 ; i<size ; i++ ){
            Node* FrontNode = q.front();
            q.pop();

            int index = LeftToRight ? i : size - i -1;
            ans[index] = FrontNode -> data ;

            if (FrontNode->left) 
                q.push(FrontNode->left);

            if (FrontNode->right)
                q.push(FrontNode->right);
        }
        LeftToRight = !LeftToRight;

        for ( auto item : ans ){
            result.push_back(item);
        }
    }

    return result;
}

int main(){
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    Node* n7 = new Node(7);
    
    n1->left = n2;
    n1->right = n3;

    n2->left = n4;
    n2->right = n5;

    n3->left = n6;
    n3->right = n7;

    vector <int> arr = zigZagTraversal(n1);
    print(arr);
    
    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;
    delete n6;
    delete n7;


    return 0;
}