#include <iostream>
#include <vector>
using namespace std;

// recursion
int climbStairs(int n) {
    if (n <= 1) return 1;

    return climbStairs(n-1) + climbStairs(n-2);
}

// memoization
int climbStairsMEMO(int n) {
    vector <int> dp(n+1,-1);
    if (n <= 1) return 1;
    if (dp[n] != -1 ) return dp[n];

    return dp[n] =  climbStairs(n-1) + climbStairs(n-2);
}


// Tabulation
int climbStairsTAB(int n) {
    vector <int> dp(n+1,-1);
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

// space optimization
int climbStairsSPACE(int n) {
    int prev1 = 1;
    int prev2 = 1;
    
    for(int i=2; i<=n; i++){
        int curr = prev1 + prev2;
        cout << "curr : " << curr << endl;
        prev1 = prev2;
        cout << "prev1 : " << prev1 << endl;
        prev2 = curr;
        cout << "prev2 : " << prev2 << endl;
    }

    return prev2;
}



int main(){
    int ans = climbStairsSPACE(5);
    cout << "No. of ways To Climb Tree : " << ans << endl;
    return 0;
}