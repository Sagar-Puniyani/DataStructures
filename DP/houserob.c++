#include <iostream>
#include <vector>
using namespace std;

// Memoization
int solve(vector<int> &nums, int index, vector <int> dp) {
    if (index == 0) return nums[0];
    if (index < 0) return 0;
    
    if (dp[index] != -1) return dp[index];

    int left = solve(nums, index-2,dp) + nums[index];
    int right = solve(nums, index-1,dp);

    return dp[index] = max(left, right);
}

int robMemo(vector<int> &nums) {
    vector<int> dp;
    int n = nums.size();
    dp.resize(n, -1);
    return solve(nums, n - 1,dp);
}

// Tabulation
int solveTab(vector<int> &nums, int index, vector <int> dp) {
    if (index == 0) return nums[0];
    if (index < 0) return 0;
    
    dp[0] = nums[0];
    dp[1] = max(nums[0] , nums[1]);

    for (int i=2; i<=index; i++){
        int left = dp[i-2] + nums[i];
        int right = dp[i-1];
        dp[i] = max(left, right);
    }

    return dp[index];
}

int robTab(vector<int> &nums) {
    vector<int> dp;
    int n = nums.size();
    dp.resize(n, -1);
    cout << n << endl;
    return solveTab(nums, n - 1,dp);
}

int main() {
    vector<int> nums = {2, 1, 4, 9};
    int ans = robTab(nums);
    cout << "Ans: " << ans << endl;

    return 0;
}
