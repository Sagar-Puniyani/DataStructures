#include <iostream>
#include <queue>
#include <map>
using namespace std;


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x) : data(x) , left(NULL) , right(NULL){}
};


Node* CreatePareentMapping(Node* root , int target , map <Node* , Node* > &mappingToParent ){
    if ( root == NULL ) return nullptr;

    Node* result = NULL;

    queue <Node* > q;
    q.push(root);
    mappingToParent[root] = NULL;
    

    while ( !q.empty() ) {
        Node* FrontNode = q.front();
        q.pop();

        if ( FrontNode->data == target ){
            result = FrontNode;
        }

        if ( FrontNode->left ){
            mappingToParent[FrontNode->left] = FrontNode;
            q.push(FrontNode->left);
        }

        if ( FrontNode->right ){
            mappingToParent[FrontNode->right] = FrontNode;
            q.push(FrontNode->right);
        }

    }

    return result;

}

void burnTree(map <Node* , Node* > ParentMapping , Node* TargetNode , int &timeToBurn ){
    
    if ( ! TargetNode){
        return;
    }

    map<Node* , bool>  isVisited;

    queue <Node*> q;
    q.push(TargetNode);
    isVisited[TargetNode] = true;

    while ( !q.empty() ) {
        
        bool flag = false;
        int size = q.size();
        for ( int i=0 ; i<size ; i++){
            Node* FrontNode = q.front();
            q.pop();

            if ( FrontNode->left && !isVisited[FrontNode->left]){
                flag = true;
                q.push(FrontNode->left);
                isVisited[FrontNode->left] = true;
            }

            if ( FrontNode->right && !isVisited[FrontNode->right]){
                flag = true;
                q.push(FrontNode->right);
                isVisited[FrontNode->right] = true;
            }

            if ( ParentMapping[FrontNode] && !isVisited[ParentMapping[FrontNode]]){
                flag = true;
                q.push(ParentMapping[FrontNode]);
                isVisited[ParentMapping[FrontNode]] = true;
            }
        }
        if (flag) timeToBurn++;
    }
}

int minTime(Node* root, int target) {


    // Step1 : Create Mapping for parent Node 
    // Step2 : Find target Node 
    map <Node* , Node* > ParentMapping;
    Node* TargetNode = CreatePareentMapping(root , target , ParentMapping);


    // step3 : Mark the Visited Node's
    int timeToBurn = 0;
    burnTree( ParentMapping , TargetNode , timeToBurn);

    return timeToBurn;

}

void Inorder( Node* root ){
    if ( root == NULL ){
        return;
    }

    Inorder(root->left);
    cout <<"  " <<  root->data ;
    Inorder(root->right);
}

int main(){

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
    
    
    n1->left = n2;
    n1->right = n3;

    n2->left = n4;
    n2->right = n5;

    n3->right = n6;

    n5->left = n7;
    n5->right = n8;

    n6->right = n9;

    n9->right = n10;

    Inorder(n1);
    cout << endl;
    int TimeToBurn = minTime(n1 , 8);
    cout << "Time To Burn : " << TimeToBurn << endl;



    
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

    return 0;
}
