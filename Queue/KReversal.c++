#include <iostream>
#include <queue>
#include <stack>
using namespace std;
template <typename T>
void print(const queue<T>& q) {
    cout << "[ ";
    queue<T> tempQueue = q;  // Create a copy to avoid modifying the original queue
    while (!tempQueue.empty()) {
        cout << tempQueue.front() << "  ";
        tempQueue.pop();
    }
    cout << "]\n";
}

queue<int> modifyQueue(queue<int> q, int k) {
    stack <int> s;
    int n =  q.size();

    for ( int i=0 ; i<k ; i++ ){
        s.push(q.front());    
        q.pop();
    }

    while ( !s.empty() ) {
        q.push(s.top());
        s.pop();
    }

    for ( int i=0 ; i<(n-k) ; i++ ) {
        int frontElement = q.front();
        q.pop();
        q.push(frontElement);
    }
    return q;
}


int main()
{
    queue<int> q ;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    int k = 3;
    q = modifyQueue( q  ,  k );
    print(q);
    return 0;
}