#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

bool linersearch(vector<int> arr, int num)
{
    for (int item : arr)
    {
        if (num == item)
        {
            return true;
        }
    }
    return false;
}

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n)
{
    int longest = 1;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        int cnt = 1;

        while (linersearch(arr, num + 1) == true)
        {
            num += 1;
            cnt += 1;
        }

        longest = max(longest, cnt);
    }

    return longest;
}

int longestSuccessiveElements(vector<int> arr, int n)
{
    // sort the array
    sort(arr.begin(), arr.end());
    int lastSmallest = INT_MIN;
    int cnt = 0;
    int longest = 1;

    for (int i = 0; i < n; i++)
    {
        if (lastSmallest == arr[i] - 1)
        {
            cnt++;
            lastSmallest = arr[i]; // new term in seq
        }
        else if (arr[i] != lastSmallest)
        {
            lastSmallest = arr[i];
            cnt = 1;
        }

        longest = max(longest, cnt);
    }
    return longest;
}

int longestSuccessiveElementsOPT(vector<int> arr)
{
    // set data structure
    unordered_set<int> st;
    int cnt = 0, longest = 0;

    for (int item : arr)
    {
        st.insert(item);
    }

    for (int item : st)
    {
        if (st.find(item - 1) == st.end())
        {
            cnt = 1;
            int x = item;
            while (st.find(x + 1) != st.end())
            {
                x++;
                cnt++;
            }
            longest = max(longest, cnt);
        }

        else
        {
            continue;
        }
    }

    return longest;
}

int main()
{
    vector<int> arr = {3, 8, 5, 7, 6};
    int n = 5;
    int ans = lengthOfLongestConsecutiveSequence(arr, n);
    cout << "longest consecutive sequence : " << ans << endl;

    vector<int> nums = {100, 101, 1, 1, 3, 3, 2, 4, 5, 6, 7, 108, 109};
    int res = longestSuccessiveElements(nums, nums.size());
    cout << "Longest seq : " << res << endl;

    int result = longestSuccessiveElementsOPT(nums);
    cout << "Longest sequence : " << result << endl;
    return 0;
}