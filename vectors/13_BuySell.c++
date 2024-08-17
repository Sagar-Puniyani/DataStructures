#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int mini = prices[0];
    int n = prices.size();
    int ans = INT_MIN;

    for (int i = 1; i < n; i++)
    {
        mini = min(mini, prices[i]);
        ans = max(ans , prices[i] - mini);
    }

    return ans;
}

int main()
{
    vector <int> arr = {7,6,4,3,1};
    int ans = maxProfit(arr);
    cout << "Max Profit : " << ans << endl;
    return 0;
}