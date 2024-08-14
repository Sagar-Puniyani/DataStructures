#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int majorityElementHash(vector<int> &nums)
{
    unordered_map<int, int> mp;

    for (int item : nums)
    {
        mp[item]++;
    }

    for (int item : nums)
    {
        if (mp[item] > nums.size() / 2)
        {
            return item;
        }
    }

    return -1;
}

//  Moore’s Voting Algorithm
int MooreAlgo(vector<int> &nums)
{
    int element = 0, count = 0;

    for (int i = 0; i < nums.size(); i++)
    {

        if (count == 0)
        {
            element = nums[i];
            count = 1;
        }

        else if (nums[i] == element)
        {
            count++;
        }

        else
        {
            count--;
        }
    }

    cout << "element : " << element << endl;
    int cnt = 0;
    for (int j = 0; j < nums.size(); j++)
    {
        if (nums[j] == element)
            cnt++;
    }
    if (cnt > (nums.size() / 2))
        return element;

    return -1;
}

int main()
{
    vector<int> arr = {6,5,5};
    int ans = majorityElementHash(arr);
    cout << "Ans : " << ans << endl;

    int majority = MooreAlgo(arr);
    cout << "majority voting : " << majority << endl;

    return 0;
}