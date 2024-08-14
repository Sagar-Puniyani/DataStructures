#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int> &nums)
{

    int sum = 0, maxi = nums[0];
    int start = 0;
    int ansStart = -1, ansEnd = -1;

    for (int i = 0; i < nums.size(); i++)
    {
        if (sum == 0)
            start = i;
        sum += nums[i];

        if (sum > maxi)
        {
            maxi = sum;

            ansStart = start;
            ansEnd = i;
        }

        if (sum < 0)
            sum = 0;
    }

    cout << "start : " << ansStart << "  end : " << ansEnd << endl;

    return maxi;
}

int main()
{
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int ans = maxSubArray(arr);
    cout << "max subArray sum : " << ans << endl;

    return 0;
}