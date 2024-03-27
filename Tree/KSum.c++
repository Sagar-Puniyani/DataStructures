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

void print(vector <int> arr ){
    for ( auto item : arr ){
        cout << item << "  ";
    }
    cout << endl;
}


void solution(Node* root , vector <int> &path , int &count , int k  ){
    if ( root == NULL ) return ;

    else {
        path.push_back(root->data);


        int size = path.size();
        int sum = 0;
        for ( int i = size-1 ; i>=0 ; i-- ){
            sum += path[i];
            if (sum == k ){
                count ++;
            }
        }
        solution(root->left , path , count ,  k);
        solution(root->right , path , count , k );

        path.pop_back();
    }
}



int sumK(Node * root,int k){
    vector<int> path;
    int count = 0;
    solution( root , path , count , k );
    return count;
}


int  main(){
    Node* n1 = new Node(1);
    Node* n2 = new Node(3);
    Node* n3 = new Node(-1);
    Node* n4 = new Node(2);
    Node* n5 = new Node(1);
    Node* n6 = new Node(4);
    Node* n7 = new Node(5);
    Node* n8 = new Node(1);
    Node* n9 = new Node(1);
    Node* n10 = new Node(2);
    Node* n11 = new Node(6);
    
    
    n1->left = n2;
    n1->right = n3;

    n2->left = n4;
    n2->right = n5;

    n3->left = n6;
    n3->right = n7;

    n5->left = n8;

    n6->left = n9;
    n6->right = n10;

    n7->right = n11;

    int ans = sumK(n1 , 5 );
    cout << "Ans : " << ans << endl;

    
    
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