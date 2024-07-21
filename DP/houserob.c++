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

// space optimization 
int Rob(vector<int> &nums) {
    int n = nums.size();
    if (n == 0) return nums[0];
    if (n < 0) return 0;
    
    int temp1 = nums[0];
    int temp2 = max(nums[0] , nums[1]);
    int curr = -1;

    for (int i=2; i< n; i++){
        int left = temp1 + nums[i];
        int right = temp2;
        curr = max(left, right);
        temp1 = temp2;
        temp2 = curr;
    }

    return temp2;
}

int RobCircular(vector<int> &nums) {
    vector <int> temp1, temp2;
    int n = nums.size();
    for (int i=0; i<n;  i++){
        if( i != 0) temp1.push_back(nums[i]);
        if( i != n-1) temp2.push_back(nums[i]);
    }

    int ans1 = Rob(temp1);
    int ans2 = Rob(temp2);

    return max(ans1, ans2);
}

int main() {
    vector<int> nums = {2, 1, 4, 9};
    int ans = RobCircular(nums);
    cout << "Ans: " << ans << endl;

    return 0;
}
