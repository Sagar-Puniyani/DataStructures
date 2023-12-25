#include <iostream>
using namespace std;


int main() {
    int outside = 10;

    cout << "&outside = " << &outside << endl;

    // This is a lambda function that captures 'outside' by reference
    auto lambdaFunction = [&outside]()-> int {
        cout << "outside: " << outside << endl;
        *(&outside) += 5;
        return outside;
    };

    lambdaFunction();  // Output: outside: 10
    cout << "outside after lambdaFunction: " << outside << endl;  // Output: outside after lambdaFunction: 15

    return 0;
}