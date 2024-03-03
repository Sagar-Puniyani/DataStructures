#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void print ( queue <int> q ){
    if ( !q.empty() ){
        int value = q.front();
        cout << "  " << value ;
        q.pop();
        print(q);
    }
}


queue<int> rev(queue<int> q){
    stack <int> s;
    queue <int> queue;

    
    while ( !q.empty() ){
        int val = q.front();
        q.pop();
        s.push(val);
    }

    while ( !s.empty()){
        int val = s.top();
        s.pop();
        queue.push(val);
    }

    return queue;
}


queue<int> Reversal(queue <int>& q){

    if ( q.empty() ){
        return q;
    }

    int value = q.front();
    q.pop();
    Reversal(q);
    q.push(value);

    return q;
}

int main()
{
    queue <int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    

    print(q);
    cout << endl;
    

    queue <int> q1 = rev(q);
    print(q1);
    cout << endl;


    queue <int> q2 =   Reversal(q);
    print(q2);
    cout << endl;


    return 0;
}