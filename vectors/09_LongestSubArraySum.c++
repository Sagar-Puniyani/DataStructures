#include <iostream>
#include <map>
#include <vector>
using namespace std;

// positives and negatives
int longestSubarrayWithSumK(vector<int> a, long long k)
{
    map<long long, int> prefixSumMap;
    long long sum = 0;
    int maxLen = 0;

    for (int i = 0; i < a.size(); i++)
    {
        // prefixSum
        sum += a[i];

        // sum == k, update maxLen
        if (sum == k)
        {
            maxLen = max(maxLen, i + 1);
        }

        long long rem = sum - k;
        // find remaining
        if (prefixSumMap.find(rem) != prefixSumMap.end())
        {
            int len = i - prefixSumMap[rem];
            maxLen = max(len, maxLen);
        }

        if (prefixSumMap.find(sum) == prefixSumMap.end())
        {
            prefixSumMap[sum] = i;
        }
    }

    return maxLen;
}

int longestSubarrayWithSumKOPT(vector<int> a, long long k)
{

    int left = 0, right = 0;
    int n = a.size();
    long long sum = 0;
    int maxLen = 0;

    while (right < n)
    {

        while (left <= right && sum > k)
        {
            sum -= a[left];
            left++;
        }

        // if sum = k, update the maxLen i.e. answer:
        if (sum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }

        right++;
        if (right < n)
            sum += a[right];
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 1, 0, 0, 1, 1, 1};
    int ans = longestSubarrayWithSumK(arr, 3);
    cout << "longest subarray sum : " << ans << endl;

    return 0;
}