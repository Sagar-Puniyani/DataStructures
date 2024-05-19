#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

class compare{
    public:
    bool operator()(Node* a , Node* b){
        return a->data > b->data;
    }
};


Node* mergeKLists(vector<Node*> &listArray){

    priority_queue<Node* , vector<Node*> , compare > pq;
    // Step1 : k elements in heap

    for ( auto item : listArray){
        if ( item != NULL ){
            pq.push(item);
        }
    }

    // step2 : arrange in the result  linked list 
    Node* head = nullptr;
    Node* tail = nullptr;

    while( !pq.empty() ){
        Node* top = pq.top();
        pq.pop();

        if ( top->next != NULL ){
            pq.push(top->next);
        }

        // push nodes in ans
        if ( head == NULL ){
            head = top;
            tail = top;
        }
        else {
            tail->next = top;
            tail = top;
        }
    }

    return head;
}


// Function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}


int main() {

    Node* list1 = new Node(1);
    list1->next = new Node(4);
    list1->next->next = new Node(5);

    Node* list2 = new Node(1);
    list2->next = new Node(3);
    list2->next->next = new Node(4);

    Node* list3 = new Node(2);
    list3->next = new Node(6);

    Node* list4 = nullptr; 

    Node* list5 = new Node(-1);
    list5->next = new Node(0);
    list5->next->next = new Node(2);
    list5->next->next->next = new Node(7);

    vector<Node*> listArray = {list1, list2, list3, list4, list5};

    Node* mergedHead = mergeKLists(listArray);

    // Print the merged list
    printList(mergedHead);

    return 0;
}