#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void print ( queue <int> q ){
    for ( auto element : q ){
        cout << " " <<  element ;
    }
    cout << endl;
}

void interLeaveQueue(queue<int>& q){
    int mid = q.size() / 2 ;
    stack <int> s;

    // push first half in stack 
    for ( int i=0 ; i<mid ; i++ ){
        int value = q.front();
        q.pop();
        s.push(value);
    }

    // stack -> queue 
    while ( ! s.empty() ) {
        int value = s.top();
        s.pop();
        q.push(value);
    }

    // Get frist half of queue 
    for ( int i=0 ; i<mid ; i++ ){
        int value = q.front();
        q.pop();
        q.push(value);
    }

    // fetch first half in stack 
    for( int i=0 ; i<mid ; i++ ){
        int value = q.front();
        q.pop();
        s.push(value);
    }

    // Fetching Intervaled Data from queu and stack 
    while ( !s.empty() ) {

        // from stack 
        int value = s.top();
        s.pop();
        q.push(value);

        // from queue 
        value = q.front();
        q.pop();
        q.push(value);
    }
}

int main()
{
    queue <int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    

    print(q);
    interLeaveQueue(q);
    print(q);

    return 0;
}