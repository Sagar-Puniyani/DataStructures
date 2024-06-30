#include <iostream>
#include <vector>
using namespace std;

int fib(int n , vector<int> &dp ){
    if (n<=1 ) return n;

    if (dp[n] != -1 ) return dp[n];

    return dp[n] = fib(n-1, dp) + fib(n-2 , dp);
}

int main(){
    #ifndef IO
    freopen("input.txt" ,"r", stdin);
    freopen("output.txt" ,"w", stdout);
    #endif

    int n;
    cin >> n;
    vector<int> dp(n+1,-1);
    int ans = fib(n, dp);
    cout << ans;


    return 0;
}