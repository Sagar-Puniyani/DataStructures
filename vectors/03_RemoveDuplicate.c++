#include <iostream>
#include <set>
#include <vector>
using namespace std;

int solve(vector<int> &nums)
{
    set<int> s;

    for (int item : nums)
    {
        s.insert(item);
    }

    int k = s.size();

    int j = 0;
    for (int item : s)
    {
        nums[j++] = (item);
    }

    return k;
}

int removeDuplicates(vector<int> &nums)
{
    int i=0;
    for (int j = 0; j < nums.size(); j++)
    {
        if ( nums[i] != nums[j]){
            nums[++i] = nums[j];
        }
    }

    return i+1;
}

int main()
{
    vector<int> nums = {0,0,0,1,1,2,2,2,3,3,3};
    int ans = removeDuplicates(nums);
    cout << "Duplicates are : " << ans << endl;

    return 0;
}