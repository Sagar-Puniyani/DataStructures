#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void printArr(vector<int> arr)
{
    for (int item : arr)
    {
        cout << item << "  ";
    }
    cout << endl;
}

vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> ans(2, -1);

    for (int i = 0; i < nums.size(); i++)
    {
        int rem = target - nums[i];
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (rem == nums[j])
            {
                ans[0] = i;
                ans[1] = j;
            }
        }
    }

    return ans;
}

vector<int> twoSumHash(vector<int> &nums, int target)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++)
    {

        int rem = target - nums[i];
        if (mp.find(rem) != mp.end())
        {
            return {mp[rem], i};
        }
        mp[nums[i]] = i;
    }

    return {-1, -1};
}

// Ducth National Flag Algorithm

void sortColors(vector<int> &nums)
{
    int low=0, mid=0, high=nums.size()-1;

    while ( mid < high){
        if (nums[mid] == 0){
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1){
            mid++;
        }
        else {
            swap(nums[mid], nums[high]);
            high--;
        }
    }

}

int main()
{
    vector<int> arr = {3, 2, 4};
    vector<int> ans = twoSum(arr, 6);

    vector<int> ansHash = twoSumHash(arr, 6);

    printArr(ans);
    printArr(ansHash);

    vector<int> colors = {0,1,2,0,1,0,1,0,2,0,1,0,1};
    sortColors(colors);
    printArr(colors);

    return 0;
}