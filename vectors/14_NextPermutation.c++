#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printArr(vector<int> arr)
{
    for (int item : arr)
    {
        cout << item << " ";
    }
    cout << endl;
}

void nextPermutation(vector<int> &nums)
{
    // break point
    int index = -1;
    int n = nums.size();

    for (int i = n - 2; i > 0; i--)
    {
        if (nums[i - 1] > nums[i])
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        reverse(nums.begin(), nums.end());
    }
    else
    {
        for (int i = n - 1; i > index - 1; i--)
        {
            if (nums[i] > nums[index - 1])
            {
                swap(nums[i], nums[index - 1]);
                break;
            }
        }
        reverse(nums.begin() + index, nums.end());
    }
}

int main()
{
    // STL Algorithm to next permutation
    vector<int> nums = {2,1,5,4,3,0,0};
    next_permutation(nums.begin(), nums.end());
    printArr(nums);

    return 0;
}