#include <iostream>
#include <map>
using namespace std;

map<int, int> m;

int tribonacci(int n) {
    m[0] = 0;
    m[1] = 1;
    m[2] = 1;
    if (m.find(n) != m.end()) return m[n];

    m[n] = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
    return m[n];
}

int main(){

    int ans = tribonacci(10);
    cout << "Ans : " << ans << endl;
}
