#include <iostream>
#include <set>
#include <vector>
#include "23_threeSum.c++"
using namespace std;

vector<vector<int>> foursumTarget(vector<int> &nums, int target)
{
    int n = nums.size();
    set<vector<int>> st;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if (sum == target)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        sort(temp.begin(), temp.end());

                        st.insert(temp);
                    }
                }
            }
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> fourSumBetter(vector<int> &arr, int target)
{
    int n = arr.size();
    set<vector<int>> st;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            set<long long> hashSet;
            for (int k = j + 1; k < n; k++)
            {
                long long sum = arr[i] + arr[j];
                sum += arr[k];

                long long remaining = target - sum;
                if (hashSet.find(remaining) != hashSet.end())
                {
                    vector<int> temp = {arr[i], arr[j], arr[k], (int)(remaining)};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }

                hashSet.insert(arr[k]);
            }
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> fourSumOPT(vector<int> &arr, int target)
{
    vector<vector<int>> ans;
    int n = arr.size();

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (j > i+1 && arr[j] == arr[j - 1])
                continue;

            // 2 pointer
            int k = j + 1;
            int l = n - 1;

            while (k < l)
            {
                long long sum = arr[i];
                sum += arr[j];
                sum += arr[k];
                sum += arr[l];

                if (sum == target)
                {
                    vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                    ans.push_back(temp);
                    k++;
                    l--;

                    // skip the duplicates:
                    while (k < l && arr[k] == arr[k - 1])
                        k++;
                    while (k < l && arr[l] == arr[l + 1])
                        l--;
                }

                else if (sum < target)
                    k++;
                else
                    l--;
            }
        }
    }

    return ans;
}
int main()
{
    vector<int> nums = {2,2,2,2,2};
    int target = 8;
    vector<vector<int>> ans = fourSumOPT(nums, target);
    printMatrix(ans);

    return 0;
}