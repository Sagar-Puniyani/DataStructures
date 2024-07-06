#include <iostream>
#include <vector>
using namespace std;

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