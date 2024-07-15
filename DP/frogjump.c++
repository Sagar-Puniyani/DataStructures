#include <iostream>
#include <vector>
using namespace std;

// Function to find the minimum cost to reach the end using at most 'k' jumps
int solveUtil(int n, vector<int>& height, vector<int>& dp, int k) {
    dp[0] = 0;

    // Loop through the array to fill in the dp array
    for (int i = 1; i < n; i++) {
        int mmSteps = INT_MAX;

        // Loop to try all possible jumps from '1' to 'k'
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                int jump = dp[i - j] + abs(height[i] - height[i - j]);
                mmSteps = min(jump, mmSteps);
            }
        }
        dp[i] = mmSteps;
    }
    return dp[n - 1]; // The result is stored in the last element of dp
}

// Function to find the minimum cost to reach the end of the array
int solve(int n, vector<int>& height, int k) {
    vector<int> dp(n, -1); // Initialize a memoization array to store calculated results
    return solveUtil(n, height, dp, k);
}


// memorization
int minimumEnergy(vector<int>& height, int n) {
    vector <int> dp(n+1,-1);
    dp[1] = 0;
    dp[2] = abs(height[0] - height[1]);

    if ( n<=2 ) return dp[n];
    if (dp[n] != -1 ) return dp[n];
    
    int left = minimumEnergy(height , n-1) + abs(height[n-1] - height[n-2]);
    int right = (n>2) ? minimumEnergy(height , n-2) + abs(height[n-1] - height[n-3]) : INT_MAX;
    dp[n] = min(left , right);

    return dp[n];
}

// Tabulation 
int minimumEnergy(vector<int>& height, int n) {
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i < n; i++) {
        dp[i] = min(dp[i], dp[i-1] + abs(height[i] - height[i-1]));
        if (i > 1) {
            dp[i] = min(dp[i], dp[i-2] + abs(height[i] - height[i-2]));
        }
    }

    return dp[n-1]; 
}

int main(){
    vector<int> height = {10, 50, 10};
    int ans = minimumEnergy(height, 3);
    cout << "ans : " << ans << endl;
    return 0;
}