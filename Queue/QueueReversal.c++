#include <iostream>
#include <queue>
#include <stack>
using namespace std;


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


queue<int> Reversal(queue <int> q){

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
    
    return 0;
}